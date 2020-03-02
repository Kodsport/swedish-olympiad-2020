// Keeps a list of all keys, and tests against all of them (in some random order).
// Fails with a large number of keys and queries.
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int N, Q;
	cin >> N >> Q;

	vector<pii> mods[2];
	map<pii, pii> modPos[2];
	set<int> seenYes, seenNo;

	rep(i,0,Q) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			if (seenYes.count(x)) goto fail;
			if (seenNo.count(x)) goto win;
			trav(pa, mods[0]) {
				if (x % pa.second == pa.first) goto fail;
			}
			trav(pa, mods[1]) {
				if (x % pa.second == pa.first) goto fail;
			}
win:
			cout << "Nej" << endl;
			seenNo.insert(x);
			continue;
fail:
			cout << "Ja" << endl;
			seenYes.insert(x);
		}
		else {
			int mu = (t == 2 ? 1 : -1);
			int a, b;
			cin >> a >> b;
			pii key(a, b);
			int size = (b < 20 ? 0 : 1);

			if (mu == -1) seenYes.clear();
			else seenNo.clear();

			pii& pa = modPos[size][key];
			if (mu == 1) {
				if (!pa.second++) {
					pa.first = sz(mods[size]);
					mods[size].push_back(key);
				}
			} else {
				assert(pa.second > 0);
				if (!--pa.second) {
					int p = pa.first;
					int p2 = sz(mods[size]) - 1;
					swap(modPos[size][mods[size][p]].first, modPos[size][mods[size][p2]].first);
					swap(mods[size][p], mods[size][p2]);
					assert(modPos[size][key].first == p2);
					modPos[size].erase(key);
					mods[size].pop_back();
				}
			}
		}
	}
}
