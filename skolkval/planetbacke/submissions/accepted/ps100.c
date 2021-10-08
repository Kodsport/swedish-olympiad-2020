#include <stdio.h>
int MAX(int p, int q) { return p>q?p:q; }

int N,M;
char map[11][10];
int taken[10][10], T[10][10];

int MLX(int r, int c, int now) {
	int m,x,y;
	if(r<0 || r==N || c<0 || c==M || taken[r][c]) return 0;
	if(map[r][c]==now) {
		taken[r][c]=1;
		m=0;
		for(x=-1;x<=1;x++) for(y=-1;y<=1;y++) if(x!=0 || y!=0) m=MAX(m, MLX(r+y,c+x,now));
		taken[r][c]=0;
		return 1+m;
	}
	else return T[r][c];
}

int main() {
	int i,j,n;
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++) {
		scanf("%s", map[i]);
		for(j=0;j<M;j++) {
			map[i][j]-='0';
			T[i][j]=0;
			taken[i][j]=0;
		}
	}
	for(n=0;n<=9;n++) {
		for(i=0;i<N;i++) for(j=0;j<M;j++) if(map[i][j]==n) T[i][j]=MLX(i,j,n);
	}
	n=0;
	for(i=0;i<N;i++) for(j=0;j<M;j++) n=MAX(n,T[i][j]);
	printf("%d\n", n);
	return 0;
}
