#include "validator.h"

void run(){
  int nMax = Arg("nMax");
  int mMax = Arg("mMax");
  int kMax = Arg("kMax");

  int n = Int(1,nMax); Space();
  int m = Int(1,mMax); Space();
  long long maxk = (long long)n * (long long)m;
  maxk = min(maxk, (long long)kMax);
  int k = Int(1, (int)maxk); Endl();

  for(int i = 0; i < k; i++){
    Int(1, n); Space();
    Int(1, m); Space();
    Int(-1e9, 1e9); Endl();
  }
  
  Eof();
}