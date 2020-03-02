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
	vector<short> sieve(N); // no way this will give false positives :)
	rep(i,0,Q) {
		int t, a, b;
		cin >> t >> a;
		if (t == 1) {
			cout << (sieve[a] ? "Ja" : "Nej") << '\n';
		} else {
			cin >> b;
			if (t == 2) {
				for (int i = a; i <= N; i += b) sieve[i]++;
			} else {
				for (int i = a; i <= N; i += b) sieve[i]--;
			}
		}
	}
}
