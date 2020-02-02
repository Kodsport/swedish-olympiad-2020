#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);
uniform_int_distribution<> DD(0, 1000000000);

ll random(ll r){
    return (1000000000 * ll(DD(eng)) + DD(eng))%r;
}

ll n,m,T,k,q;
const ll big = 1000000007;
const ll MAXN = 300001;
const ll inv = 500000004;

vector<vi> C(MAXN, vi());
ll ST[MAXN] = {0};
ll dist[MAXN] = {0};
ll PAR[MAXN] = {0};

void dfs1(ll i, ll par){
    ST[i] = 1;
    PAR[i] = par;
    trav(j, C[i]){
        if(j != par){
            dist[j] = 1 + dist[i];
            dfs1(j,i);
            ST[i] += ST[j];
        }
    }
}

vi ANS;

void dfs2(ll i, ll par){
    ANS.push_back(i);
    trav(j, C[i]){
        if(j != par){
            dfs2(j,i);
        }
    }
}

map<ll,ll> M;
bool dp(ll i, ll par, ll c, ll m2){
    if(i == k)return (m2 == 0);
    if(m2 <= 0)return 0;
    if(c == sz(C[i]))return dp(PAR[i], i, 0, m2-1);
    ll j = C[i][c];
    if(j == par || j == PAR[i])return dp(i, par, c+1, m2);

    ll h = n*(n*(n*i + par) + c) + m2;
    if(M.find(h) != M.end())return M[h];

    bool ans = (dp(i, par, c+1, m2)||dp(i, par, c+1, m2-ST[j]));
    M[h] = ans;
    return ans;
}

void solve(ll i, ll par){
    ANS.push_back(i);
    if(i == k)return;
    rep(c, 0, sz(C[i])){
        ll j = C[i][c];
        if(j != par && j != PAR[i]){
            if(dp(i, par, c+1, m - ST[j] - sz(ANS))){
                dfs2(j, i);
            }
        }
    }
    solve(PAR[i], i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> k;
    if(n > 1000){
        cout << "-1\n";
        return 0;
    }
    k--;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs1(k, -1);

    rep(c1,0,n){
        ANS.clear();
        solve(c1,-1);
        if(sz(ANS) == m){
            trav(j, ANS){
                cout << j+1 << " ";
            }cout << "\n";
            return 0;
        }
    }
    cout << "-1\n";

    return 0;
}


