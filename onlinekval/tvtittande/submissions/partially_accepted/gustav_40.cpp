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

    vi lengths(k);
    for(int i = 0; i < k; i++)
        cin >> lengths[i];

    vi days(n);
    vvi a(n);
    for(int i = 0; i < n; i++){
        int day, c;
        cin >> day >> c;
        days[i] = day;
        a[i] = vi(c);
        for(int j = 0; j < c; j++){
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    int pday = -1;
    int hours = 0;
    for(int i = 0; i < n; i++){
        hours += (days[i]-pday-1)*10;
        pday = days[i];
        for(int m : a[i]){
            bool seen = false;
            for(int x = 0; x < i && !seen; x++){
                for(int y : a[x]) if(y == m) seen = true;
            }
            if(!seen) hours -= lengths[m];
        }
        if(hours < 0){
            cout << "Nej" << endl;
            return 0;
        }
    }
    cout << "Ja" << endl;
}
