#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int maxN = Arg("maxN");
	int maxM = Arg("maxM");
	int maxT = Arg("maxT");
	
	int N = Int(1, maxN);
	Space();
	Int(1, maxM);
	Endl();
	SpacedInts(N, 1, maxT);
}
