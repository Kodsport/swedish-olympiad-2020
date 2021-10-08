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
    if(!valid(i,j))return 0;
    int x = 0;
    int y = (j-i)/2 + 1;
    while(x < y-1){
        int mid = (x+y)/2;
        if(valid(i+mid, j-mid)){
            x = mid;
        }
        else{
            y = mid;
        }
    }
    int i2 = i+x;
    int j2 = j-x;

    int i3 = i2;
    int jj = j2+1;
    while(i3 < jj-1){
        int mid = (i3+jj)/2;
        if(valid(mid,j2)){
            i3 = mid;
        }
        else{
            jj = mid;
        }
    }

    if((i3-i2)%2 == 1)return 1;

    int ii = i2-1;
    int j3 = j2;
    while(ii < j3-1){
        int mid = (j3+ii)/2;
        if(valid(i2,mid)){
            j3 = mid;
        }
        else{
            ii = mid;
        }
    }
    if((j2-j3)%2 == 1)return 1;
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
        assert(q == 1 && a == 1 && b == n);
        a--;
        b--;
        cout << solve(a,b) << "\n";
    }

    return 0;
}


