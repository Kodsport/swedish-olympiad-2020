// Like naive2_sl.cpp, but with Barrett reduction. Wins 30%!
#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Barrett {
	int m, k, mod;
	Barrett(int mod) : mod(mod) {
		k = 0;
		int p2 = 1;
		while (p2 <= mod)
			p2 <<= 1, k++;
		m = (int)((ll)p2 * p2 / mod);
	}

	// Works if a < mod^2, i.e. sqrt(N) < mod
	int reduce(ll a) {
		ll q = (m * a) >> (2*k);
		int r = (int)(a - q * mod);
		r = (r >= mod ? r - mod : r);
		return r;
	}

	__attribute__((always_inline))
	inline int equals(ll a, int x) {
		ll q = (m * a) >> (2*k);
		int r = (int)(a - q * mod);
		return x == r || x == r - mod;
	}

	bool operator<(const Barrett& other) const { return mod < other.mod; }
	bool operator==(const Barrett& other) const { return mod == other.mod; }
};

struct HM {
	// Hash set, but avoids the overhead when it's small
	__gnu_pbds::gp_hash_table<int, int> hashm;
	vi vec;
	bool small = true;

	bool has(int x) {
		if (small) {
			trav(y, vec) if (y == x) return true;
			return false;
		}
		return hashm.find(x) != hashm.end();
	}

	void add(int x, int y) {
		if ((hashm[x] += y) == 0) {
			hashm.erase(x);
		}

		small = false;
		if (sz(hashm) < 5) {
			small = true;
			vec.clear();
			trav(pa, hashm)
				vec.push_back(pa.first);
		}
	}

	bool empty() const { return hashm.empty(); }
};

struct HashMods {
	map<int, int> modPos;
	vector<pair<int, HM>> mods;

	void insert(int a, int b, int mu) {
		if (!modPos.count(b)) {
			assert(mu == 1);
			modPos[b] = sz(mods);
			mods.emplace_back(b, HM());
		}
		int pos = modPos[b];
		auto& v = mods[pos].second;
		v.add(a, mu);
		if (v.empty()) {
			assert(mu == -1);
			int pos2 = sz(mods) - 1;
			if (pos != pos2) {
				int b2 = mods.back().first;
				swap(mods[pos], mods[pos2]);
				swap(modPos[b2], modPos[b]);
			}
			mods.pop_back();
			modPos.erase(b);
		}
	}
};

struct VecModsL {
	vector<pair<int, Barrett>> mods;
	map<pair<int, Barrett>, int> modPos;

	void insert(int a, int b, int mu) {
		pair<int, Barrett> key(a, b);
		int& pos = modPos[key];
		if (mu == 1) {
			assert(pos == 0);
			pos = sz(mods);
			mods.push_back(key);
		} else {
			int p = pos, p2 = sz(mods) - 1;
			assert(modPos[mods[p2]] == p2);
			assert(modPos[mods[p]] == p);
			swap(modPos[mods[p]], modPos[mods[p2]]);
			swap(mods[p], mods[p2]);
			assert(modPos[key] == p2);
			modPos.erase(key);
			mods.pop_back();
		}
	}
};

struct VecMods {
	vector<pii> mods;
	map<pii, int> modPos;

	void insert(int a, int b, int mu) {
		pii key(a, b);
		int& pos = modPos[key];
		if (mu == 1) {
			assert(pos == 0);
			pos = sz(mods);
			mods.push_back(key);
		} else {
			int p = pos, p2 = sz(mods) - 1;
			assert(modPos[mods[p2]] == p2);
			assert(modPos[mods[p]] == p);
			swap(modPos[mods[p]], modPos[mods[p2]]);
			swap(mods[p], mods[p2]);
			assert(modPos[key] == p2);
			modPos.erase(key);
			mods.pop_back();
		}
	}
};

int main() {
	const int SMALL = 20;
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N, Q;
	cin >> N >> Q;

	VecMods smallMods, oneMods;
	VecModsL oneModsL;
	HashMods largeMods;

	map<int, map<int, int>> counts;

	int sqrtN = (int)sqrt(N) + 4;

	rep(qi,0,Q) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			int s = sz(oneModsL.mods);
			int i = 0;
			pair<int, Barrett>* list = oneModsL.mods.data();

			trav(pa, smallMods.mods) {
				int r = x % pa.second;
				if (r == pa.first) goto fail;
			}

			while (i + 4 <= s) {
				if (list[i].second.equals(x, list[i].first)) goto fail;
				i++;
				if (list[i].second.equals(x, list[i].first)) goto fail;
				i++;
				if (list[i].second.equals(x, list[i].first)) goto fail;
				i++;
				if (list[i].second.equals(x, list[i].first)) goto fail;
				i++;
			}
			while (i < s) {
				if (list[i].second.equals(x, list[i].first)) goto fail;
				i++;
			}

			trav(pa, oneMods.mods) {
				int r = x % pa.second;
				if (r == pa.first) goto fail;
			}
			trav(pa, largeMods.mods) {
				int r = x % pa.first;
				if (pa.second.has(r)) goto fail;
			}
			cout << "Nej" << endl;
			continue;
fail:
			cout << "Ja" << endl;
		}

		else {
			int mu = (t == 2 ? 1 : -1);
			int a, b;
			cin >> a >> b;

			int oldSize = sz(counts[b]);
			if ((counts[b][a] += mu) == 0)
				counts[b].erase(a);
			int newSize = sz(counts[b]);
			if (newSize == 0) counts.erase(b);
			if (oldSize == newSize) continue;

			int largeB = (b > sqrtN);
			if (b < SMALL) {
				smallMods.insert(a, b, mu);
			} else {
				if (newSize == 1) {
					trav(pa, counts[b]) {
						if (largeB) oneModsL.insert(pa.first, b, 1);
						else        oneMods.insert(pa.first, b, 1);
					}
				}
				if (oldSize == 1) {
					if (mu == -1) {
						if (largeB) oneModsL.insert(a, b, -1);
						else        oneMods.insert(a, b, -1);
					}
					else {
						trav(pa, counts[b]) if (pa.first != a) {
							if (largeB) oneModsL.insert(pa.first, b, -1);
							else        oneMods.insert(pa.first, b, -1);
						}
					}
				}
				if (oldSize == 1 && newSize > 1) {
					trav(pa, counts[b])
						largeMods.insert(pa.first, b, 1);
				}
				if (oldSize > 1 && newSize == 1) {
					trav(pa, counts[b])
						largeMods.insert(pa.first, b, -1);
					largeMods.insert(a, b, -1);
				}
				if (oldSize > 1 && newSize > 1) {
					largeMods.insert(a, b, mu);
				}
			}
		}
	}
}
