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

const int MAXN = 2001;

int DP[MAXN][MAXN][2] = {0};
bool DPC[MAXN][MAXN][2] = {0};
int NEXT[MAXN][MAXN][2] = {0};

string s1,s2;
int l1,l2;

int dp(ll i, ll j, bool skipped){
    if(i == s1.length() && j == s2.length())return 0;
    if(i == s1.length())return big;
    if(DPC[i][j][skipped])return DP[i][j][skipped];
    int ans = big;
    if(j < s2.length() && s1[i] == s2[j]){
        ans = 1 + dp(i+1, j+1, 0);
        NEXT[i][j][skipped] = 0;
    }

    int penalty = 1;
    if(!skipped)penalty += 2 * l2 - 2 * j;
    int ans2 = penalty + dp(i+1, j, 1);
    if(ans2 < ans){
        ans = ans2;
        NEXT[i][j][skipped] = 1;
    }

    DPC[i][j][skipped] = 1;
    DP[i][j][skipped] = ans;

    return ans;

}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;
    cin >> k;
    cin >> s1 >> l1 >> s2 >> l2;
    if(l1 < l2){
        swap(l1,l2);
        swap(s1,s2);
    }
    int ans = dp(0,0,0);

    if(ans >= big || sz(s1) - sz(s2) > l1 - l2){
        cout << "!\n";
        return 0;
    }

    if(k == 0)cout << '<';
    int i = 0;
    int j = 0;
    bool skipped = 0;
    string res = "";

    while(!(i == s1.length() && j == s2.length())){
        if(NEXT[i][j][skipped] == 0){
            res += s1[i];
            i++;
            j++;
            skipped = 0;
        }
        else{
            a = 0;
            while(NEXT[i][j][skipped] == 1){
                res += s1[i];
                i++;
                skipped = 1;
                a++;
            }
            for(int c1 = 0; c1 < l2 - j; c1++){
                if(i + c1 < s1.length()){
                    res += s1[i + c1];
                }
                else{
                    res += 'a';
                }
            }
            for(int c1 = 0; c1 < l2 - j; c1++){
                res += '<';
            }
        }
    }
    cout << res << "\n";
    
    return 0;
}

