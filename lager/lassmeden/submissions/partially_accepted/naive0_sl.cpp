// Simplest possible "naive" (expensive queries) solution.
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

	multiset<pii> mods;

	rep(i,0,Q) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			trav(pa, mods) {
				if (x % pa.second == pa.first) goto fail;
			}
			cout << "Nej" << endl;
			continue;
fail:
			cout << "Ja" << endl;
		}
		else {
			int a, b;
			cin >> a >> b;
			if (t == 2)
				mods.insert(pii(a, b));
			else
				mods.erase(mods.find(pii(a, b)));
		}
	}
}
