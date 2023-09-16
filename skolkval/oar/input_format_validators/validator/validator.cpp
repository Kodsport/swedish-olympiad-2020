#include "validator.h"

void run() {
	int n = Int(1, 10000);
  if (Arg("subtask", 0)) {
    int sum = 0, ind = 0;
    int a = 1, b = 1;
    for (;;) {
      ind++;
      sum += a;
      if (sum >= n) {
        assert(sum == n);
        break;
      }
      a += b;
      swap(a, b);
    }
  }
	Endl();
}
