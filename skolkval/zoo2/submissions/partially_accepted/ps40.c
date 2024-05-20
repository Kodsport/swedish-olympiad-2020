#include <stdio.h>
#include <string.h>
//Handles only the case M=0 or M=1


long long sum;
int N, K, g;

void MLX(int nr, int now, long long prop) {
	if(nr==N) sum+=prop;
	else {
		if(now==1) MLX(nr+1,0,prop*g);
		MLX(nr+1,1,prop*((now==0)?(K-g):(K-g-1)));
		}
}

int main() {
	char s[21];
	int M;
	scanf("%d %d %d", &N, &K, &M);
	if(M==0) g=0;
	else {
		scanf("%s", s);
		g=strlen(s);
	}
	sum=0;
	MLX(1,0,g);  //problematic animals
	MLX(1,1,K-g);     //social animals
	printf("%lld\n", sum);
	return 0;
}
