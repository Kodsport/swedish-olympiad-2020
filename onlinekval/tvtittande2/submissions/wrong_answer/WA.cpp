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
	
    int n, k;
    cin >> n >> k;
    vi length(k), watched(k);
    for(int i = 0; i < k; i++) cin >> length[i];
    int ans = 1;
    int hours = 0;
    int pday = -1;
    for(int i = 0; i < n; i++){
        int day, m;
        cin >> day >> m;
        hours = 10*(day-pday-1); //fel
        pday = day;
        for(int j = 0; j < m; j++){
            int c;
            cin >> c;
            c--;
            if(!watched[c]){
                watched[c] = 1;
                hours -= length[c];
            }
        }
        if(hours < 0){
            ans = 0;
        }
    }
    if(ans) cout << "Ja" << endl;
    else cout << "Nej" << endl;
}
