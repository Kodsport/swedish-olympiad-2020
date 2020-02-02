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

const int MAXN = 1000000;

int n,k,q;

int MIN[(1 << 21)];
int MAX[(1 << 21)];

int main() {
    
    cin >> n >> k;
    rep(c1,0,(1 << k)){
        MIN[c1] = n;
        MAX[c1] = -1;
    }
    rep(c1,0,n){
        string s;
        cin >> s;
        int mask = 0;
        rep(c2,0,k){
            mask *= 2;
            mask += s[c2]-'0';
        }
        MIN[mask] = min(MIN[mask],c1);
        MAX[mask] = max(MAX[mask],c1);
    }

    for(int mask = (1 << k)-1; mask >= 0; mask--){
        rep(i, 0, k){
            MIN[mask] = min(MIN[mask], MIN[(mask|(1 << i))]);
            MAX[mask] = max(MAX[mask], MAX[(mask|(1 << i))]);
        }
    }

    cin >> q;
    rep(c1,0,q){
        string s;
        cin >> s;
        int mask = 0;
        rep(c2,0,k){
            mask *= 2;
            mask += s[c2]-'0';
        }
        if(MIN[mask] == n)cout << "finns ej\n";
        if(MIN[mask] == MAX[mask])cout << MIN[mask]+1 << "\n";
        if(MIN[mask] < n && MIN[mask] != MAX[mask])cout << "vet ej\n";
    }

    return 0;
}


