#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int n = Int(1, Arg("n"));
	Space();
	int m = Int(1, Arg("m"));
	Endl();

	for(int i = 0; i<n;i++){
		string str = Line();
		assert(str.size()==m);
		for(int j = 0; j<m;j++){
			assert((str[j]=='.')||(str[j]>='0'&&str[j]<='9'));
		}
	}
}
