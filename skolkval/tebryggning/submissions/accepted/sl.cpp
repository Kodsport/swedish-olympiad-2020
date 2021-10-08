#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, N, res = 0;
	cin >> K >> N;
	vector<int> te(K);
	for (int& x : te) cin >> x;
	while (N > 0) {
		auto it = max_element(te.begin(), te.end());
		int use = min(*it, 10);
		N -= use;
		*it -= use;
		res++;
	}
	cout << res << endl;
}
