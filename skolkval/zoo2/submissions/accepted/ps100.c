#include <stdio.h>

long long T[100][20];

int main() {
	char s[21];
	int i,j,k, N, K, M;
	int ok[20][20];
	long long sum;
	scanf("%d %d %d", &N, &K, &M);
	for(i=0;i<K;i++) for(j=0;j<K;j++) ok[i][j]=(i!=j);
	for(i=0;i<M;i++) {
		scanf("%s", s);
		for(j=0;s[j];j++) for(k=0;k<j;k++) ok[s[j]-'A'][s[k]-'A']=ok[s[k]-'A'][s[j]-'A']=0;
	}
	for(i=0;i<K;i++) T[0][i]=1;
	for(k=1;k<N;k++) {
		for(i=0;i<K;i++) T[k][i]=0;
		for(i=0;i<K;i++) for(j=0;j<K;j++) if(ok[i][j]) T[k][i]+=T[k-1][j];
	}
	sum=0;
	for(i=0;i<K;i++) sum+=T[N-1][i];
	printf("%lld\n", sum);
	return 0;
}
