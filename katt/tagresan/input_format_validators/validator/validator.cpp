#include "validator.h"

void run() {
	int t = Int(0, 10);
	assert(t == (int)Arg("t"));
	Endl();
	int n = Int(1, 25000);
	Space();
	int m = Int(1, 100000);
	Endl();
	set<pair<int, int>> ed;
	for(int i = 0; i < m; i++){
		int a = Int(1, 4*n);
		Space();
		int b = Int(1, 4*n);
		Endl();
		assert(a != b);
		ed.emplace(a, b);
		ed.emplace(b, a);
	}
	assert((int)ed.size() == 2*m);
}
