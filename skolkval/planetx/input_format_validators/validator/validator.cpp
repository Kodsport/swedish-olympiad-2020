#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int n = Int(1, Arg("n", 10));
	Space();
	int m = Int(1, Arg("m", 10));
	Endl();

	int nm = Arg("nm", n*m);
  assert(n*m <= nm);

  bool has = false;
	for(int i = 0; i<n;i++){
		string str = Line();
		assert(str.size()==m);
		for(int j = 0; j<m;j++){
      if (str[j] != '.') has = true;
			assert((str[j]=='.')||(str[j]>='0'&&str[j]<='9'));
		}
	}
  assert(has);
}
