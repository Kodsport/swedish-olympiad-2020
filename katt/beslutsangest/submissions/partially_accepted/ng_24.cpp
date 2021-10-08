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

const int MAXN = 1000;

int DP[MAXN][MAXN][2] = {0};
bool DPC[MAXN][MAXN][2] = {0};
int nyttighet[MAXN][MAXN] = {0};

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}

int dp(int i, int j, bool turn){
    if(!inbounds(i,j))return 0;
    if(nyttighet[i][j] != -mod)return nyttighet[i][j];
    if(DPC[i][j][turn])return DP[i][j][turn];
    int ans = dp(i+1, j, (turn^1));
    if(turn == 0)ans = min(ans, dp(i, j+1, (turn^1)));
    if(turn == 1)ans = max(ans, dp(i, j+1, (turn^1)));
    DPC[i][j][turn] = 1;
    DP[i][j][turn] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> k;
    rep(c1,0,n){
        rep(c2,0,m){
            nyttighet[c1][c2] = -mod;
        }
    }
    rep(c1,0,k){
        cin >> a >> b >> c;
        a--;
        b--;
        nyttighet[a][b] = c;
    }
    int ans = 0;
    rep(c1,0,n){
        rep(c2,0,m){
            ans += dp(c1,c2,0);
            while(ans >= mod){ans -= mod;}
            while(ans < 0){ans += mod;}
        }
    }

    cout << ans << "\n";

    return 0;
}
