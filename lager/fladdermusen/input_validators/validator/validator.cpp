#include "validator.h"
#include <set>

void run(){
  int nMax = Arg("nMax");
  int qMax = Arg("qMax");
  int hMax = Arg("hMax");
  int wMax = Arg("wMax");
  int sMax = Arg("sMax");

  int N = Int(1,nMax); Space();
  int Q = Int(1,qMax); Space();
  int H = Int(1,hMax); Space();
  int W = Int(1,wMax); Endl();
  //assert(false);

  int cnt_stalgmite = 0;
  set<int> used_x;
  for(int i = 0; i < N; i++){
    int type = Int(1,2); Space();
    int x = Int(1,W-1);    Space();
    int y = Int(1,H-1);  Endl();
    if(used_x.count(x)) die("Duplicate x-coordinate: " + to_string(x));
    used_x.insert(x);
    if(type == 2) ++cnt_stalgmite;
  }
  if(cnt_stalgmite > sMax) die("Too many stalagmite: " + to_string(cnt_stalgmite));


  for(int i = 0; i < Q; i++){
    int x1 = Int(1,W-1); Space();
    int y1 = Int(1,H-1); Space();
    int x2 = Int(1,W-1); Space();
    int y2 = Int(1,H-1); Endl();
    if(used_x.count(x1)) die("Duplicate x-coordinate: " + to_string(x1));
    used_x.insert(x1);
    if(used_x.count(x2)) die("Duplicate x-coordinate: " + to_string(x2));
    used_x.insert(x2);
  }

  Eof();
}
