#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 51;

int DX[4] = {0,0,-1,1};
int DY[4] = {-1,1,0,0};
int dust[MAXN][MAXN] = {0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int bfs(int r1, int c1, int r2, int c2, int k){
    if(dust[r1][c1] > k)return -1;
    queue<pii> Q;
    int dist[MAXN][MAXN] = {0};
    bool mark[MAXN][MAXN] = {0};
    Q.push({r1,c1});
    dist[r1][c1] = 1;
    while(!Q.empty()){
        pii p = Q.front();
        Q.pop();
        int a1 = p.first;
        int b1 = p.second;
        if(!mark[a1][b1]){
            mark[a1][b1] = 1;
            rep(c1,0,4){
                int a2 = a1 + DX[c1];
                int b2 = b1 + DY[c1];
                if(inbounds(a2,b2) && dist[a2][b2] == 0 && dust[a2][b2] <= k){
                    dist[a2][b2] = dist[a1][b1]+1;
                    Q.push({a2,b2});
                }
            }
        }
    }
    return dist[r2][c2]-1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> q;
    rep(c1,0,q){

        rep(c2,0,n){
            rep(c3,0,m){
                dust[c2][c3]++;
            }
        }

        cin >> a;
        if(a == 1){
            cin >> b;
            b--;
            rep(c2,0,m){
                dust[b][c2] = 0;
            }
        }
        if(a == 2){
            cin >> b;
            b--;
            rep(c2,0,n){
                dust[c2][b] = 0;
            }
        }
        if(a == 3){
            int r1,c1,r2,c2,k;
            cin >> r1 >> c1 >> r2 >> c2 >> k;
            r1--;c1--;r2--;c2--;
            cout << bfs(r1,c1,r2,c2,k) << "\n";
        }
    }

    return 0;
}

