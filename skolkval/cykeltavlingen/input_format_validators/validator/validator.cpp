#include "validator.h"

void run() {
  bool samesc = Arg("samesc", false);
  int N = Int(2, Arg("maxn", 10)); Space();
  int L = Int(1, 100'000); Endl();

  int s = Int(1, 100); Space();
  int c = Int(1, 100); Endl();
  for (int i = 1; i < N; i++) {
    int si = Int(1, 100); Space();
    int ci = Int(1, 100); Endl();

    if (samesc) assert(s == si && c == ci);
  }
}
