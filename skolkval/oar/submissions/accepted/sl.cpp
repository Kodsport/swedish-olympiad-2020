#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int solve(int n) {
	int sum = 0, ind = 0;
	int a = 1, b = 1;
	for (;;) {
		ind++;
		sum += a;
		if (sum >= n) return ind;
		a += b;
		swap(a, b);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N;
	cin >> N;
	cout << solve(N) << endl;
}
