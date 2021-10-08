#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	
	string ans;
	int numRep = 0;
	for (char c : s) {
		if (!ans.empty() && c == ans.back())
			numRep++;
		else
			numRep = 0;
		if (!strchr("bcdfghjklmnpqrstvwxz", c) || numRep < 2)
			ans += c;
	}
	cout << ans << "\n";
}
