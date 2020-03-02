#include <bits/stdc++.h>
using namespace std;

int main() {
	string s1, s2;
	int l1, l2;
	
	int k;
	cin >> k;
	cin >> s1 >> l1 >> s2 >> l2;
	
	if (l1 > l2) {
		s1.swap(s2);
		swap(l1, l2);
	}
	
	if (l1 - s1.size() > l2 - s2.size()) {
		if (s1 == s2) {
			cout << s1 << "\n";
		} else {
			cout << "!\n";
		}
		return 0;
	}
	
	string ans;
	int p1 = 0;
	int p2 = 0;
	while (p2 < s2.size()) {
		if (p1 < s1.size() && s1[p1] == s2[p2]) {
			ans += s1[p1];
			p1++;
			p2++;
		} else {
			ans += s2[p2];
			int pad = max(l1 - p1, 0);
			ans.append(pad, s2[p2]);
			ans.append(pad, '<');
			p2++;
		}
	}
	
	if (p1 < s1.size() || (p2 < s2.size() && p1 < l1)) {
		cout << "!\n";
	} else {
		cout << ans << "\n";
	}
}
