#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vi;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ii> vii;

#define rep(i,a,b) for(ll i = a; i<b;i++)
#define per(i,a,b) for(ll i = a; i>=b; i--)
#define inf LLONG_MAX
#define all(x) x.begin(),x.end()
#define sz(x) (ll)(x).size()
#define trav(a,x) for(auto &a: x)
#define mp(x,y) make_pair(x,y)

bool pos = true;
vii points;
vi _;
vector<vi> __;

ll quad(ll x1, ll y1, ll x2, ll y2){
  if (x1 < x2 && y1 < y2){
    if (pos) return 1;
    else return 0;
  } else if (x1 < x2 && y1 > y2){
    if (pos) return 0;
    else return 3;
  } else if (x1 > x2 && y1 < y2){
    if (pos) return 2;
    else return 1;
  } else if (x1 > x2 && y1 > y2){
    if (pos) return 3;
    else return 2;
  } else if (x1 == x2 && y1 < y2) return -1;
  else if (x1 == x2 && y1 > y2) return -3;
  else if (x1 < x2 && y1 == y2) return -4;
  else if (x1 > x2 && y1 == y2) return -2;
  else return 100;
}

bool mysort(ii a, ii b){
  ll as = abs(points[a.first].first-points[a.second].first) + abs(points[a.first].second-points[a.second].second);
  ll bs = abs(points[b.first].first-points[b.second].first) + abs(points[b.first].second-points[b.second].second);
  if (abs(points[a.first].first-points[a.second].first) == 0 || abs(points[a.first].second-points[a.second].second) == 0) {
    if (abs(points[b.first].first-points[b.second].first) == 0 || abs(points[b.first].second-points[b.second].second) == 0) {
      if (as == bs){
        if (a.first == b.first) return a.second < b.second;
        else return a.first < b.first;
      }
      else return as < bs;
    } else return true;
  } else if (abs(points[b.first].first-points[b.second].first) == 0 || abs(points[b.first].second-points[b.second].second) == 0) {
    return false;
  } else if (as == bs){
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
  } else return as < bs;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(NULL); cout.tie(NULL);
  cout << setprecision(15) << fixed;

  ll n,x,y; cin >> n;

  set<ll> X,Y;
  map<ll,ll> xm,ym;
  rep(i,0,n){
    cin >> x >> y;
    points.push_back(mp(x,y));
    X.insert(x); Y.insert(y);
  }


  ll cnt = 0;
  trav(x,X) xm.insert(mp(x,cnt++));
  cnt = 0;
  trav(y,Y) ym.insert(mp(y,cnt++));
  rep(i,0,n) {
    points[i].first = xm[points[i].first];
    points[i].second = ym[points[i].second];
  }


  ll nx = sz(X), ny = sz(Y);
  X.clear();
  Y.clear();
  xm.clear();
  ym.clear();



  vector<vi> grid; _.assign(ny,-1); grid.assign(nx,_);
  vector< vector<vi> > nxt; _.assign(4,-1); __.assign(ny,_); nxt.assign(nx,__);

  ll dx[5] = {1,0,-1,0,1};
  ll dy[5] = {0,1,0,-1,0};

  //rep(i,0,nx) rep(j,0,ny) grid[i][j] = -1;
  rep(i,0,n) grid[points[i].first][points[i].second] = i;
  //rep(i,0,nx) rep(j,0,ny) rep(d,0,4) nxt[i][j][d] = -1;
/*
  cout << nx << " " << ny << endl;
  rep(i,0,nx) {
    rep(j,0,ny) {
      if (grid[i][j] == -1) cout << ". ";
      else cout << "# ";
    }
    cout << endl;
  }
*/
  rep(i,0,n){
    rep(d,0,4){
      ll cx = points[i].first-dx[d], cy = points[i].second-dy[d];
      while (cx >= 0 && cy >= 0 && cx < nx && cy < ny && grid[cx][cy] == -1){
        nxt[cx][cy][d] = i;
        cx -= dx[d]; cy -= dy[d];
      }
      if (cx >= 0 && cy >= 0 && cx < nx && cy < ny) nxt[cx][cy][d] = i;
    }
  }


  ll dp1[n][n];
  ll dp2[n][n];
  rep(i,0,n) rep(j,0,n) dp1[i][j] = 0;
  rep(i,0,n) rep(j,0,n) dp2[i][j] = 0;

  vii pps;
  rep(i,0,n) rep(j,i+1,n) { pps.push_back(mp(i,j)); pps.push_back(mp(j,i)); }
  sort(all(pps),mysort);

  rep(_k,0,n*(n-1)){
    ll i = pps[_k].first, j = pps[_k].second;
    ll xi = points[i].first, yi = points[i].second;
    ll xj = points[j].first, yj = points[j].second;
    ll tp = quad(xi, yi, xj, yj);
    if (tp < 0) {
      tp = -(tp%4);
      if (nxt[xi][yi][tp] == j) dp1[i][j] = 2;
      ll k = nxt[xj][yj][tp];
      if (k != -1) {
        dp1[i][k] = max(dp1[i][k], dp1[i][j]+1);
      }
      k = nxt[xj][yj][(tp+1)%4];
      if (k != -1) {
        dp1[i][k] = max(dp1[i][k], dp1[i][j]+1);
      }
    } else {
      ll xm,ym,xn,yn;
      if (tp%2) { xm = xj; ym = yi; xn = xi; yn = yj;}
      else { xm = xi; ym = yj; xn = xj; yn = yi;}
      if (grid[xm][ym] == -1) dp1[i][j] = 0;
      else {
        dp1[i][j] = max(ll(3),dp1[i][j]);
        ll k = nxt[xj][yj][tp], m = grid[xm][ym], kt = nxt[xn][yn][(tp+1)%4];
        ll cx, cy;

        if (kt != -1) dp1[m][kt] = max(dp1[i][j]+dp1[j][kt]-1, dp1[m][kt]);

        while (k != -1){
          cx = points[k].first, cy = points[k].second;
          if (tp%2) { xn = xi; yn = cy;}
          else { xn = cx; yn = yi;}

          dp1[i][k] = max(dp1[i][k], dp1[i][j]+dp1[j][k]-1);
          kt = nxt[xn][yn][(tp+1)%4];
          if (kt != -1) dp1[m][kt] = max(dp1[i][k]+dp1[k][kt]-1, dp1[m][kt]);
          k = nxt[cx][cy][tp];
        }
      }
    }
  }

  pos = false;

  rep(_k,0,n*(n-1)){
    ll i = pps[_k].first, j = pps[_k].second;
    ll xi = points[i].first, yi = points[i].second;
    ll xj = points[j].first, yj = points[j].second;
    ll tp = quad(xi, yi, xj, yj);
    if (tp < 0) {
      tp = -(tp%4);
      if (nxt[xi][yi][tp] == j) dp2[i][j] = 2;
      ll k = nxt[xj][yj][tp];
      if (k != -1) {
        dp2[i][k] = max(dp2[i][k], dp2[i][j]+1);
      }
      k = nxt[xj][yj][(tp+3)%4];
      if (k != -1) {
        dp2[i][k] = max(dp2[i][k], dp2[i][j]+1);
      }
    } else {
      ll xm,ym,xn,yn;
      if (tp%2) { xm = xj; ym = yi; xn = xi; yn = yj;}
      else { xm = xi; ym = yj; xn = xj; yn = yi;}
      if (grid[xm][ym] == -1) dp2[i][j] = 0;
      else {
        dp2[i][j] = max(ll(3),dp2[i][j]);
        ll k = nxt[xj][yj][tp], m = grid[xm][ym], kt = nxt[xn][yn][(tp+3)%4];
        ll cx, cy;

        if (kt != -1) dp2[m][kt] = max(dp2[i][j]+dp2[j][kt]-1, dp2[m][kt]);

        while (k != -1){
          cx = points[k].first, cy = points[k].second;
          if (tp%2) { xn = xi; yn = cy;}
          else { xn = cx; yn = yi;}

          dp2[i][k] = max(dp2[i][k], dp2[i][j]+dp2[j][k]-1);
          kt = nxt[xn][yn][(tp+3)%4];
          if (kt != -1) dp2[m][kt] = max(dp2[i][k]+dp2[k][kt]-1, dp2[m][kt]);
          k = nxt[cx][cy][tp];
        }
      }
    }
  }

  rep(i,0,n) dp1[i][i] = dp2[i][i] = 1;

  _.assign(4,0); __.assign(ny,_);
  vector<vector<vi> > ma1,ma2; ma1.assign(nx,__); ma2.assign(nx,__);

  rep(i,0,nx) rep(j,0,ny) rep(k,0,4) ma1[i][j][k] = ma2[i][j][k] = 0;

  rep(i,0,n) rep(j,0,n){
    ll xi = points[i].first, yi = points[i].second;
    ll xj = points[j].first, yj = points[j].second;
	if (i == j) {
		rep(d,0,4) {
        ma1[xi][yi][d] = max(ll(1),ma1[xi][yi][d]);
        ma2[xi][yi][d] = max(ll(1),ma2[xi][yi][d]);
      }
      continue;
    }
    pos = true;
    ll tp = quad(xi, yi, xj, yj);
    if (tp < 0){
      tp = (-(tp%4)+1)%4;
      ma1[xj][yj][tp] = max(ma1[xj][yj][tp], dp1[i][j]);
    } else {
      ll xn,yn;
      if (tp%2) { xn = xi; yn = yj;}
      else { xn = xj; yn = yi; }
      tp = (tp+1)%4;
      if (grid[xn][yn] != -1) ma1[xn][yn][tp] = max(ma1[xn][yn][tp], dp1[i][j]+dp1[j][nxt[xn][yn][(tp+2)%4]]);
      else ma1[xn][yn][tp] = max(ma1[xn][yn][tp], dp1[i][j]+dp1[j][nxt[xn][yn][(tp+2)%4]]-1);
    }

    pos = false;
    tp = quad(xi, yi, xj, yj);
    if (tp < 0){
      tp = (-(tp%4)+3)%4;
      ma2[xj][yj][tp] = max(ma2[xj][yj][tp], dp2[i][j]);
    } else {
      ll xn,yn;
      if (tp%2) { xn = xi; yn = yj;}
      else { xn = xj; yn = yi; }
      tp = (tp+3)%4;
      if (grid[xn][yn] != -1) ma2[xn][yn][tp] = max(ma2[xn][yn][tp], dp2[i][j]+dp2[j][nxt[xn][yn][(tp+2)%4]]);
      else ma2[xn][yn][tp] = max(ma2[xn][yn][tp], dp2[i][j]+dp2[j][nxt[xn][yn][(tp+2)%4]]-1);
    }

  }

  ll DX[4] = {1,1,-1,1};
  ll DY[4] = {1,1,1,-1};
  rep(tp,0,4){
    ll x,y;
    if (tp == 2) x = nx-2;
    else x = 1;

    while(x >= 0 && x < nx){

      if (tp == 3) y = ny-2;
      else y = 1;

      while(y >= 0 && y < ny){
        if (grid[x][y] != -1) {
          ma1[x][y][tp] = max(ma1[x][y][tp], ma1[x-dx[tp]][y-dy[tp]][tp]+1);
          ma2[x][y][tp] = max(ma2[x][y][tp], ma2[x-dx[tp]][y-dy[tp]][tp]+1);
        } else {
          ma1[x][y][tp] = max(ma1[x][y][tp], ma1[x-dx[tp]][y-dy[tp]][tp]);
          ma2[x][y][tp] = max(ma2[x][y][tp], ma2[x-dx[tp]][y-dy[tp]][tp]);
        }
        y += DY[tp];
      }
      x += DX[tp];
    }
  }

  ll ans = 0;
  rep(x,0,nx) rep(y,0,ny) rep(d,0,4) ans = max(ans,max(ma1[x][y][d], ma2[x][y][d]));

  rep(x,0,nx) rep(y,0,ny){
    if (x != nx-1) ans = max(ans, ma1[x][y][0]+ma2[x+1][y][2]);
    if (x != nx-1) ans = max(ans, ma2[x][y][0]+ma1[x+1][y][2]);
    if (y != 0) ans = max(ans, ma1[x][y][3]+ma2[x][y-1][1]);
    if (y != 0) ans = max(ans, ma2[x][y][3]+ma1[x][y-1][1]);
  }
/*
  rep(x,0,nx) rep(y,0,ny){
    if (x != nx-1) if (ans == ma1[x][y][0]+ma2[x+1][y][2]) cout << x << " " << y << " " << 0 << endl;
    if (x != nx-1) if (ans == ma2[x][y][0]+ma1[x+1][y][2]) cout << x << " " << y << " " << 1 << endl;
    if (y != 0) if (ans == ma1[x][y][3]+ma2[x][y-1][1]) cout << x << " " << y << " " << 2 << endl;
    if (y != 0) if (ans == ma2[x][y][3]+ma1[x][y-1][1]) cout << x << " " << y << " " << 3 << endl;
  }
*/
  cout << ans << endl;

}
