#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define trav(x, v) for(auto &x : v)
using namespace std;
typedef pair<int,int> pii;

void maxeq(int &a, int x){
	a = max(a,x);
}

int compress(vector<int> &v){
	map<int, int> ren;
	trav(x, v) ren[x];
	int ix = 0;
	trav(pa, ren) pa.second = ix++;
	trav(x, v) x = ren[x];
	return ix;
}

int dx[] = {1,0,-1,0},
    dy[] = {0,1,0,-1};

int n, mx, my;
vector<int> x, y;
vector<vector<int> > hitta, nasta[4], cnt[4], spir[2][4];

int antal_stolpar(int dir, int fx, int fy, int tx, int ty){
	return cnt[dir][fx][fy] - cnt[dir][tx][ty];
}

bool in_bounds(int r, int c){
	return r >= 0 && c >= 0 && r < mx && c < my;
}

struct State;

vector<vector<State> > states[2][4];

struct State {
	int ori, cur, prv, dir, deg = 0, rek = 1;
	State(){};

	int nxdir(){
		return (dir + (ori ? 3 : 1))%4;
	}
	pii horn(bool mitt){
		return (mitt ^ (dir%2)) ? pii(x[prv], y[cur]) : pii(x[cur], y[prv]);
	}
	State* rakt_fram(){
		int i = nasta[dir][x[cur]][y[cur]];
		return i==n ? 0 : &states[ori][dir][i][prv];
	};
	State* svang(){
		int i = nasta[nxdir()][horn(0).first][horn(0).second];
		int m = hitta[horn(1).first][horn(1).second];
		assert(m < n);
		return i==n ? 0 : &states[ori][nxdir()][i][m];
	};
	void dfs(){
		State* s = rakt_fram();
		if(s && !s->deg++) s->dfs();
		s = svang();
		if(s && !((s->deg)++)) s->dfs();
	}
	void calc(){
		int tx = horn(0).first, ty = horn(0).second;
		if(ori){
			tx += dx[nxdir()];
			ty += dy[nxdir()];
		}
		if(in_bounds(tx,ty))
			maxeq(spir[ori][nxdir()][tx][ty],
				rek + antal_stolpar(nxdir(), x[cur], y[cur], tx, ty));
		State *s = rakt_fram();
		if(s){
			maxeq(s->rek, rek+1);
			if(--s->deg == 0) s->calc();
		}
		s = svang();
		if(s){
			maxeq(s->rek,
				rek + antal_stolpar(nxdir(), x[cur], y[cur], x[s->cur], y[s->cur]));
			if(--s->deg == 0) s->calc();
		}
	}
};

int main(){
	cin.exceptions(cin.failbit);

	cin >> n;
	x.resize(n);
	y.resize(n);
	rep(i,0,n) cin >> x[i] >> y[i];
	mx = compress(x);
	my = compress(y);
	hitta.resize(mx, vector<int>(my, n));
	rep(t,0,4) nasta[t].resize(mx, vector<int>(my, n));
	rep(t,0,4) cnt[t].resize(mx, vector<int>(my));
	rep(o,0,2) rep(t,0,4) spir[o][t].resize(mx, vector<int>(my));

	rep(i,0,n) hitta[x[i]][y[i]] = i;

	rep(t,0,4) rep(r0,0,mx) rep(c0,0,my){
		int r = r0, c = c0;
		if(t < 2){
			r = mx-1-r;
			c = my-1-c;
		}
		int r1 = r + dx[t], c1 = c + dy[t];
		if(in_bounds(r1,c1)){
			nasta[t][r][c] = hitta[r1][c1]<n ? hitta[r1][c1] : nasta[t][r1][c1];
			cnt[t][r][c] = cnt[t][r1][c1] + (hitta[r1][c1] < n);
		}
	}

	rep(o,0,2) rep(t,0,4) states[o][t].resize(n, vector<State>(n));
	rep(o,0,2) rep(t,0,4) rep(i,0,n) rep(j,0,n){
		states[o][t][i][j].ori = o;
		states[o][t][i][j].dir = t;
		states[o][t][i][j].cur = i;
		states[o][t][i][j].prv = j;
	}
	rep(o,0,2) rep(t,0,4) rep(i,0,n) states[o][t][i][i].dfs();
	rep(o,0,2) rep(t,0,4) rep(i,0,n) states[o][t][i][i].calc();

	rep(o,0,2) rep(t,0,4) rep(r0,0,mx) rep(c0,0,my){
		int r = r0, c = c0;
		if(t >= 2){
			r = mx-1-r;
			c = my-1-c;
		}
		int r1 = r + dx[t], c1 = c + dy[t];
		if(in_bounds(r1,c1)){
			maxeq(spir[o][t][r1][c1], spir[o][t][r][c] + (hitta[r1][c1] < n));
		}
	}

	int ans = n ? 1 : 0;
	rep(t,0,4) rep(r,0,mx) rep(c,0,my){
		maxeq(ans, spir[0][t][r][c] + spir[1][t^2][r][c] - (hitta[r][c]<n));
	}

	cout << ans << endl;
}
