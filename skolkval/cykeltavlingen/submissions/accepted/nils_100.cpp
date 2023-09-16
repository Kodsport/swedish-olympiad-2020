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

vi S,C;
int n,L;

double test(double t){
    double res = 0.0;
    rep(c1,0,n){
        if(L <= t*S[c1])continue;
        if(S[c1] >= C[c1])res += L+1;
        else res += (C[c1] * L - S[c1] * C[c1] * t) / double(C[c1] - S[c1]);
    }
    return res;
}

int main() {

    cin >> n >> L;
    rep(c1,0,n){
        int a,b;
        cin >> a >> b;
        S.push_back(a);
        C.push_back(b);
    }

    double l = 0.0;
    double r = L;

    for(int c1 = 0; c1 < 200; c1++){
        double mid = (l + r)/2.0;
        if(test(mid) <= L){
            r = mid;
        }
        else{
            l = mid;
        }
    }

    cout << setprecision(18) << l << "\n";

    return 0;
}

