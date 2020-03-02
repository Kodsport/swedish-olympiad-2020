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

string s1,s2;
int L1,L2;
int n1,n2;

bool subseq(int i, int j){
    if(j < 0)return 1;
    if(i < 0)return 0;
    if(s1[i] == s2[j])return subseq(i-1,j-1);
    return subseq(i-1,j);
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);

    ll a,b,c;
    cin >> k;
    cin >> s1 >> L1;
    cin >> s2 >> L2;

    if(s1.length() < s2.length()){
        swap(s1,s2);
        swap(L1,L2);
    }

    n1 = s1.length();
    n2 = s2.length();

    if(s1.length() - s2.length() > L1 - L2 || !subseq(n1-1,n2-1)){
        cout << "!\n";
        return 0;
    }

    string ans = "";

    int i = 0;
    int curr = 0;

    rep(c1,0,n1){
        ans += s1[c1];
        if(curr == L2)continue;
        curr++;

        if(s1[c1] != s2[i]){
            int extra = L2 - curr + 1;
            rep(c2,0,extra){
                ans += 'a';
            }
            rep(c2,0,extra){
                ans += '<';
            }
            curr--;
        }
        else{
            i++;
        }
    }
    cout << ans << "\n";

    return 0;
}


