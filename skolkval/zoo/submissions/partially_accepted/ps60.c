#include <stdio.h>

long long sum;
int ok[20][20];
int N, K, M;

void MLX(int nr, int now) {
	int i;
	if(nr==N) sum+=1;
	else for(i=0;i<K;i++) if(ok[now][i]) MLX(nr+1,i);
}

int main() {
	char s[21];
	int i,j,k;
	scanf("%d %d %d", &N, &K, &M);
	for(i=0;i<K;i++) for(j=0;j<K;j++) ok[i][j]=(i!=j);
	for(i=0;i<M;i++) {
		scanf("%s", s);
		for(j=0;s[j];j++) for(k=0;k<j;k++) ok[s[j]-'A'][s[k]-'A']=ok[s[k]-'A'][s[j]-'A']=0;
	}
	sum=0;
	for(i=0;i<K;i++) MLX(1,i);
	printf("%lld\n", sum);
	return 0;
}
