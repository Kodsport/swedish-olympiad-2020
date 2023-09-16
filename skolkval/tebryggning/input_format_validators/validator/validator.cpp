#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int K = Int(1, Arg("maxk", 10));
	Space();
	int m = Int(1, 100);
  Endl();
  vector<int> A = SpacedInts(K, 1, 100);
  for (int a : A) m -= a;
  assert(m <= 0);
}
