#include <bits/stdc++.h>
using namespace std;

string s;
size_t r[2000000], t = -1, i, n;

int main() {
	cin >> s;
	n = s.size();
	s += s;
	copy(&s[0], &s[2*n], r);
	partial_sum(r, r+2*n, r);
	for (i = 0; i < n; i++)
		t = min(t, r[n/2 + i] - r[i]);
	cout << (n * 43 - t) / 20 << endl;
}
