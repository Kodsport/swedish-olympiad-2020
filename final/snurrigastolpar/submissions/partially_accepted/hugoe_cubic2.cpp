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
        ll k = nxt[xj][yj][tp];
        if (k != -1) {
          dp1[i][k] = max(dp1[i][k], dp1[i][j]+1);
        }
        ll m = grid[xm][ym];
        k = nxt[xn][yn][(tp+1)%4];
        if (k != -1) {
          dp1[m][k] = max(dp1[i][j]+dp1[j][k]-1, dp1[m][k]);
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
        ll k = nxt[xj][yj][tp];
        if (k != -1) {
          dp2[i][k] = max(dp2[i][k], dp2[i][j]+1);
        }
        ll m = grid[xm][ym];
        k = nxt[xn][yn][(tp+3)%4];
        if (k != -1) {
          dp2[m][k] = max(dp2[i][j]+dp2[j][k]-1, dp2[m][k]);
        }
      }
    }
  }

  rep(i,0,n) dp1[i][i] = dp2[i][i] = 1;





  ll ans = 0;

  vector<vector<vi> > ma1,ma2;
  _.assign(2,0); __.assign(ny,_);
  ma1.assign(nx,__); ma2.assign(nx,__);

  rep(x,0,nx){
    rep(i,0,n) rep(j,0,n){
      ll xi = points[i].first, yi = points[i].second;
      ll xj = points[j].first, yj = points[j].second;
      if (abs(xi-xj)+abs(xi-x) != abs(xj-x)) continue;
      //cout << x << " " << i << " " << j << " " << xi << " " << yi << " " << xj << " " << yj << endl;

      pos = true;
      ll tp;
      if (i == j) {
        if (x < xj) tp = 0;
        else tp = 2;
        if (x == xj) ma1[x][yj][((tp+2)%4)/2] = max(ma1[x][yj][((tp+2)%4)/2],1);
        else if (grid[x][yj] == -1) ma1[x][yj][((tp+2)%4)/2] = max(ma1[x][yj][((tp+2)%4)/2],dp1[j][nxt[x][yj][tp]]);
        else ma1[x][yj][((tp+2)%4)/2] = max(ma1[x][yj][((tp+2)%4)/2],dp1[j][nxt[x][yj][tp]]+1);
      } else {
        tp = quad(xi,yi,xj,yj);
        if (tp < 0) tp = (1-(tp%4))%4;
        else tp = (tp+1)%4;
        if (tp%2 == 0) {
          if (abs(xj+dx[(tp+2)%4]-x) > abs(xj-x)){
            if (xj == x) ma1[x][yj][tp/2] = max(ma1[x][yj][tp/2], dp1[i][j]);
            else if (grid[x][yj] == -1) ma1[x][yj][tp/2] = max(ma1[x][yj][tp/2], dp1[i][j]+dp1[j][nxt[x][yj][(tp+2)%4]]-1);
            else ma1[x][yj][tp/2] = max(ma1[x][yj][tp/2], dp1[i][j]+dp1[j][nxt[x][yj][(tp+2)%4]]);
          }
        }
      }

      //cout << "  " << ma1[x][yj][0] << " " << ma1[x][yj][1] << endl;

      pos = false;
      if (i == j) {
        if (x < xj) tp = 0;
        else tp = 2;
        if (x == xj) ma2[x][yj][((tp+2)%4)/2] = max(ma2[x][yj][((tp+2)%4)/2],ll(1));
        else if (grid[x][yj] == -1) ma2[x][yj][((tp+2)%4)/2] = max(ma2[x][yj][((tp+2)%4)/2],dp2[j][nxt[x][yj][tp]]);
        else ma2[x][yj][((tp+2)%4)/2] = max(ma2[x][yj][((tp+2)%4)/2],dp2[j][nxt[x][yj][tp]]+1);
      } else {
        tp = quad(xi,yi,xj,yj);
        if (tp < 0) tp = (3-(tp%4))%4;
        else tp = (tp+3)%4;
        if (tp%2 == 0) {
          if (abs(xj+dx[(tp+2)%4]-x) > abs(xj-x)){
            if (xj == x) ma2[x][yj][tp/2] = max(ma2[x][yj][tp/2], dp2[i][j]);
            else if (grid[x][yj] == -1) ma2[x][yj][tp/2] = max(ma2[x][yj][tp/2], dp2[i][j]+dp2[j][nxt[x][yj][(tp+2)%4]]-1);
            else ma2[x][yj][tp/2] = max(ma2[x][yj][tp/2], dp2[i][j]+dp2[j][nxt[x][yj][(tp+2)%4]]);
          }
        }
      }
      //cout << "  " << ma2[x][yj][0] << " " << ma2[x][yj][1] << endl;

    }
  }

  rep(y,0,ny){
    rep(x,0,nx-1){
      ans = max(ans, ma1[x][y][0]+ma2[x+1][y][1]);
      ans = max(ans, ma2[x][y][0]+ma1[x+1][y][1]);
    }
  }

  rep(x,0,nx) rep(y,0,ny) {
    ans = max(ans,ma1[x][y][0]);
    ans = max(ans,ma1[x][y][1]);
    ans = max(ans,ma2[x][y][0]);
    ans = max(ans,ma2[x][y][1]);
  }

  rep(y,0,ny){
    rep(i,0,nx) rep(d,0,2) ma1[i][y][d] = ma2[i][y][d] = 0;
    rep(i,0,n) rep(j,0,n){
      ll xi = points[i].first, yi = points[i].second;
      ll xj = points[j].first, yj = points[j].second;
      if (abs(yi-yj)+abs(yi-y) != abs(yj-y)) continue;

      pos = true;
      ll tp;
      if (i == j) {
        if (y < yj) tp = 1;
        else tp = 3;
        if (y == yj) ma1[xj][y][((tp+2)%4)/2] = max(ma1[xj][y][((tp+2)%4)/2],1);
        else if (grid[xj][y] == -1) ma1[xj][y][((tp+2)%4)/2] = max(ma1[xj][y][((tp+2)%4)/2],dp1[j][nxt[xj][y][tp]]);
        else ma1[xj][y][((tp+2)%4)/2] = max(ma1[xj][y][((tp+2)%4)/2],dp1[j][nxt[xj][y][tp]]+1);
      } else {
        tp = quad(xi,yi,xj,yj);
        if (tp < 0) tp = (1-(tp%4))%4;
        else tp = (tp+1)%4;
        if (tp%2 == 1) {
          if (abs(yj+dy[(tp+2)%4]-y) > abs(yj-y)){
            if (yj == y) ma1[xj][y][tp/2] = max(ma1[xj][y][tp/2], dp1[i][j]);
            else if (grid[xj][y] == -1) ma1[xj][y][tp/2] = max(ma1[xj][y][tp/2], dp1[i][j]+dp1[j][nxt[xj][y][(tp+2)%4]]-1);
            else ma1[xj][y][tp/2] = max(ma1[xj][y][tp/2], dp1[i][j]+dp1[j][nxt[xj][y][(tp+2)%4]]);
          }
        }
      }

      pos = false;
      if (i == j) {
        if (y < yj) tp = 1;
        else tp = 3;
        if (y == yj) ma2[xj][y][((tp+2)%4)/2] = max(ma2[xj][y][((tp+2)%4)/2],1);
        else if (grid[xj][y] == -1) ma2[xj][y][((tp+2)%4)/2] = max(ma2[xj][y][((tp+2)%4)/2],dp2[j][nxt[xj][y][tp]]);
        else ma2[xj][y][((tp+2)%4)/2] = max(ma2[xj][y][((tp+2)%4)/2],dp2[j][nxt[xj][y][tp]]+1);
      } else {
        tp = quad(xi,yi,xj,yj);
        if (tp < 0) tp = (3-(tp%4))%4;
        else tp = (tp+3)%4;
        if (tp%2 == 1) {
          if (abs(yj+dy[(tp+2)%4]-y) > abs(yj-y)){
            if (yj == y) ma2[xj][y][tp/2] = max(ma2[xj][y][tp/2], dp2[i][j]);
            else if (grid[xj][y] == -1) ma2[xj][y][tp/2] = max(ma2[xj][y][tp/2], dp2[i][j]+dp2[j][nxt[xj][y][(tp+2)%4]]-1);
            else ma2[xj][y][tp/2] = max(ma2[xj][y][tp/2], dp2[i][j]+dp2[j][nxt[xj][y][(tp+2)%4]]);
          }
        }
      }
    }
  }

  rep(x,0,nx){
    rep(y,0,ny-1){
      ans = max(ans, ma1[x][y][0]+ma2[x][y+1][1]);
      ans = max(ans, ma2[x][y][0]+ma1[x][y+1][1]);
    }
  }

  rep(x,0,nx) rep(y,0,ny){
    ans = max(ans,ma1[x][y][0]);
    ans = max(ans,ma1[x][y][1]);
    ans = max(ans,ma2[x][y][0]);
    ans = max(ans,ma2[x][y][1]);
  }

  cout << ans << endl;

}
