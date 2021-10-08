#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> slen(k);
	vector<bool> done(k);
	for (int i = 0; i < k; i++)
		cin >> slen[i];
	
	int watchTime = 0;
	int prevDay = 0;
	for (int i = 0; i < n; i++) {
		int day, numS;
		cin >> day >> numS;
		
		watchTime += 10 * (day - prevDay);
		prevDay = day + 1;
		
		for (int j = 0; j < numS; j++) {
			int s;
			cin >> s;
			s--;
			if (!done[s]) {
				watchTime -= slen[s];
				done[s] = true;
			}
		}
		
		if (watchTime < 0) {
			cout << "Nej\n";
			return 0;
		}
	}
	
	cout << "Ja\n";
}
