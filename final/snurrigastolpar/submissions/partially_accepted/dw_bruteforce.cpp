#include<bits/stdc++.h>
#define rep(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

int sgn(int x){
	return (x>0) - (x<0);
}

int dx[] = {1,0,-1,0},
    dy[] = {0,1,0,-1};

int n;
vector<int> x, y;

bool disj(int a, int b, int i, int j){
	return min(x[a],x[b]) > max(x[i], x[j]) ||
	       min(x[i],x[j]) > max(x[a], x[b]) ||
	       min(y[a],y[b]) > max(y[i], y[j]) ||
	       min(y[i],y[j]) > max(y[a], y[b]);
}

vector<int> path;
int ans = 0;

void rek(int dir){
	ans = max(ans, (int)path.size());
	int b = path.back();
	rep(_,0,2){
		rep(i,0,n) if(sgn(x[i]-x[b]) == dx[dir] && sgn(y[i]-y[b]) == dy[dir]){
			rep(k,0,(int)path.size()-2){
				if(!disj(path[k], path[k+1], b, i)) goto done;
			}
			path.push_back(i);
			rek(dir);
			path.pop_back();
			done: ;
		}
		dir = (dir+1)%4;
	}
}

int main(){
	cin >> n;
	x.resize(n);
	y.resize(n);
	rep(i,0,n) cin >> x[i] >> y[i];

	rep(i,0,n){
		path.push_back(i);
		rek(0);
		rek(2);
		path.pop_back();
	}
	cout << ans << endl;
}
