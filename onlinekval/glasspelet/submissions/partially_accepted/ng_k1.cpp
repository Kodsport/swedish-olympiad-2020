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
const ll MAXN = 400001;

int R[MAXN] = {0};
int F[MAXN] = {0};

vi A;

bool valid(int i, int j){
    return R[i] <= j;
}

int solve(int i, int j){
    if(j-i+1 > k+1)return 123213;
    if(!valid(i,j))return 0;
    if(valid(i+1,j) || valid(i,j-1))return 1;
    return 2;
}

int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);

    ll a,b,c;

    cin >> n >> k >> q;
    rep(c1,0,n){
        cin >> a;
        A.push_back(a);
    }

    int r = n;
    int dist = 0;
    for(int c1 = n-1; c1 >= 0; c1--){
        F[A[c1]]++;
        if(F[A[c1]] == 1)dist++;
        if(dist == k && r == n)r--;
        while(r >= 0 && dist == k && F[A[r]] > 1){
            F[A[r]]--;
            r--;
        }
        R[c1] = r;
    }

    rep(c1,0,q){
        cin >> a >> b;
        a--;
        b--;
        cout << solve(a,b) << "\n";
    }

    return 0;
}

