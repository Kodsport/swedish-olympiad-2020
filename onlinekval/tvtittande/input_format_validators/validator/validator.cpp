#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int nMax = Arg("nMax");
	int kMax = Arg("kMax");

	int n = Int(1, nMax);
	Space();
	int k = Int(1, kMax);
	Endl();
	SpacedInts(k, 1, 1000000);
	long long csum = 0;
	int prevday = 0;
	vector<int> w(k);
	for(int i = 0; i < n; i++){
		int d = Int(prevday+1, 200000);
		prevday = d;
		Space();
		int c = Int(1, 200000);
		csum += c;
		Space();
		vector<int> serier = SpacedInts(c, 1, k);
		AssertUnique(serier);
		for (int x : serier) {
			w[x-1] = 1;
		}
	}
	assert(csum <= 200000);
	for(auto x : w) assert(x == 1);
}
