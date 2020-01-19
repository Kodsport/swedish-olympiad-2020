#include "validator.h"
#include <set>
using namespace std;

void run() {
	int nMax = Arg("nMax");
	int mMax = Arg("mMax");

	int n = Int(1, nMax);
	Endl();

	set<pair<int, int>> seen;
	for (int i = 0; i < n; i++) {
		int x = Int(1, mMax);
		Space();
		int y = Int(1, mMax);
		Endl();
		seen.emplace(x, y);
	}

	assert((int)seen.size() == n);
}
