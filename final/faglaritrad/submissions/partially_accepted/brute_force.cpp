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

vi now;
vi ans;
bool taken[MAXN] = {0};

bool free(ll i){
    trav(y, C[i]){
        if(!taken[y])return 1;
    }
    return 0;
}

ll iterations = 0;

void brute(){
    if(sz(ans) > 0 || iterations > 100000000)return;
    iterations++;
    if(sz(now) == m){
        if(now.back() == k){
            ans = now;
        }
        return;
    }
    vi nex;
    if(sz(now) == 0){
        rep(c1,0,n){
            iterations++;
            nex.push_back(c1);
        }
    }
    else{
        for(int c1 = sz(now)-1;c1 >= 0; c1--){
            if(free(now[c1])){
                trav(y, C[now[c1]]){
                    iterations++;
                    if(!taken[y])nex.push_back(y);
                }
                break;
            }
        }
    }
    random_shuffle(all(nex));   // Can do something smarter here...

    trav(y, nex){
        taken[y] = 1;
        now.push_back(y);
        brute();
        now.pop_back();
        taken[y] = 0;
    }
}

int main() {

    cin >> n >> m >> k;
    k--;
    rep(c1,0,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        C[a].push_back(b);
        C[b].push_back(a);
    }
    brute();
    if(sz(ans) > 0){
        rep(c1,0,m){
            cout << ans[c1]+1 << " ";
        }cout << "\n";
    }
    else{
        cout << "-1\n";
    }
    return 0;
}

