#include "validator.h"

void run(){
  int nMax = Arg("nMax");
  int mMax = Arg("mMax");
  int qMax = Arg("qMax");

  int n = Int(1,nMax); Space();
  int m = Int(1,mMax); Space();
  int q = Int(1,qMax); Endl();

  for(int i = 0; i < q; i++){
    int type = Int(1,3); Space();
    if(type == 1){
        int row = Int(1,n); Endl();
    }
    if(type == 2){
        int col = Int(1,m); Endl();
    }
    if(type == 3){
        Int(1,n); Space();
        Int(1,m); Space();
        Int(1,n); Space();
        Int(1,m); Space();
        Int(0,q); Endl();
    }
  }
  Eof();
}