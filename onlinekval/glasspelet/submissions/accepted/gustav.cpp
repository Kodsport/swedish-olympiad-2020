#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
const int inf = 0x3f3f3f3f;
const ll linf = 123456789012345678;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define debug(x) cerr << #x << " = " << x << endl
#define sz(x) ((int)(x).size())

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	
    int n, k, q;
	cin >> n >> k >> q;
    vi a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vpi t;
    vi content(k);
    int present = 0;
    int p1 = 0, p2 = 0;
    while(1){
        if(present < k){
            if(p2 == n) break;
            if(content[a[p2]] == 0) present++;
            content[a[p2]]++;
            p2++;
            if(present == k) t.emplace_back(p1-1, p2-1);
        }
        else{
            if(content[a[p1]] == 1) present--;
            content[a[p1]]--;
            p1++;
            if(present < k) t.emplace_back(p1-1, p2-1);
        }
    }
    t.emplace_back(t[sz(t)-1].first, n);

    vi winner(2*n-1);
    vi minlength(2*n-1, inf);
    int ind = 0;
    for(int av = 0; av <= 2*n-2; av++){
        if(t[ind].first + t[ind].second < av) ind+=2;
        if(ind == 0) continue;
        if(ind == sz(t)-1 && av == t[ind].first + t[ind].second) break;
        int dist = abs(t[ind-1].first + t[ind-1].second - av);
        winner[av] = !(dist%2)+1;
        minlength[av] = t[ind-1].second - t[ind-1].first + dist;
        if(t[ind].first + t[ind].second == av){
            int dist = abs(t[ind+1].first + t[ind+1].second - av);
            if(dist%2) winner[av] = 1;
        }
    }

    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        l--,r--;
        if(r-l < minlength[r+l]) cout << 0 << "\n";
        else cout << winner[r+l] << "\n";
    }
}
