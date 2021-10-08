#include "validator.h"
#include <cmath>

#define sz(v) int(v.size())

void run() {
	int nMax = Arg("nMax");
	
	string str = Line();

	assert(nMax==-1||sz(str)<=nMax);
	assert(sz(str)%2==0);

	for(int i = 0;i<sz(str);i++)
		assert(str[i]=='B'||str[i]=='V');
}
