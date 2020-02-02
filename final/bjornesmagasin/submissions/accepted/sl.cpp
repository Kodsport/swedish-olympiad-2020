#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int mdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	int N, asleep;
	cin >> N >> asleep;
	int awake = 365 - asleep;
	vi wakes(N); // when bears wake up, normalized such that wakes[i] = 0
	int firstday = -1000;
	rep(i,0,N) {
		int month, day;
		char ch;
		cin >> day >> ch >> month;
		day--;
		rep(i,0,month-1) day += mdays[i];
		assert(0 <= day && day < 365);
		day = (day + asleep) % 365;
		if (i == 0) firstday = day;
		wakes[i] = (day - firstday + 365) % 365;
	}

	vi done(365 * 2);
	int res = 0;
	rep(d,awake,365) if (!done[d]) {
		int best = -1, besti = -1;
		rep(i,1,N) if (wakes[i] <= d && wakes[i] + awake > d) {
			if (wakes[i] > best) {
				best = wakes[i];
				besti = i;
			}
		}
		if (best == -1) {
			cout << -1 << endl;
			return 0;
		}
		res++;
		rep(j,0,awake) {
			done[wakes[besti] + j] = 1;
		}
	}
	cout << res << endl;
}
