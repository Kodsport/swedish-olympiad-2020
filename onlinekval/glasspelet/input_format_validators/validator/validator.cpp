#include "validator.h"

void run() {
	int n = Int(1,Arg("nMax"));
	Space();

	int k = Int(1, min(n,(int)Arg("kMax")));
    Space();

	int q = Int(1, Arg("qMax"));
	Endl();

	vector<int> values = SpacedInts(n, 0, k-1);
	assert((int)set<int>(values.begin(), values.end()).size() == k);

	string special = Arg("special");

	if (special == "ktwo") {
		assert(k == 2);
	}

	for(int i = 0; i < q; i++){
		int l = Int(1,n);
		Space();
		int r = Int(1,n);
		Endl();
		assert(l <= r);
		if(special=="small_intervals"){
			assert(r-l+1 <= k+1);
		}
		if (special == "full") {
			assert(l == 1);
			assert(r == n);
		}
	}

}

