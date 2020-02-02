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

void dfs1(ll i, ll par){
    ST[i] = 1;
    trav(j, C[i]){
        if(j != par){
            dfs1(j,i);
            ST[i] += ST[j];
        }
    }
}

vi D;

void dfs2(ll i, ll par){
    D.push_back(i);
    trav(j, C[i]){
        if(j != par){
            dfs2(j,i);
        }
    }
}

vi ANS;
void solve(ll i, ll par, ll m2){
    if(m2 == 0)return;
    ANS.push_back(par);
    if(m2 == 1)return;
    m2--;
    ll nxt = -1;
    trav(j, C[i]){
        if(j != par){
            if(ST[j] <= m2-1){
                D.clear();
                dfs2(j, i);
                reverse(all(D));
                trav(d, D){
                    ANS.push_back(d);
                }
                m2 -= sz(D);
            }
            else{
                nxt = j;
                break;
            }
        }
    }
    if(nxt != -1){
        solve(nxt, i, m2);
    }
    else{
        ANS.push_back(i);
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> m >> k;
    k--;
    rep(c1,0,n-1){
        cin >> a >> b;
        a--;
        b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    dfs1(k, -1);

    trav(j, C[k]){
        if(ST[j] >= m-1){
            solve(j, k, m);
            reverse(all(ANS));
            break;
        }
    }
    if(sz(ANS) > 0){
        trav(j, ANS){
            cout << j+1 << " ";
        }cout << "\n";
    }
    else{
        cout << "-1\n";
    }

    return 0;
}


