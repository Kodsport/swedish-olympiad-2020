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

string s1,s2;
int l1,l2;

string text(string seq, int L){
    string ans = "";
    trav(ch, seq){
        if(ch == '<' && sz(ans) > 0)ans.pop_back();
        if(ch != '<' && sz(ans) < L)ans += ch;
    }
    return ans;
}

vector<string> candidates;

void gen(string now, int L){
    if(L == 0){
        candidates.push_back(now);
        return;
    }
    gen(now+'a', L-1);
    gen(now+'b', L-1);
    gen(now+'<', L-1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;
    cin >> k;
    cin >> s1 >> l1 >> s2 >> l2;
    rep(L,1,15){
        candidates.clear();
        gen("",L);
        trav(ans, candidates){
            if(text(ans, l1) == s1 && text(ans, l2) == s2){
                cout << ans << "\n";
                return 0;
            }
        }
    }
    cout << "!\n";

    return 0;
}


