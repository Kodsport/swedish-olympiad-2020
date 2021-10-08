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

    vi lengths(k), seen(k);
    for(int i = 0; i < k; i++)
        cin >> lengths[i];

    vi saved(n);
    int pday = -1;
    for(int i = 0; i < n; i++){
        int day, m;
        cin >> day >> m;
        int hours = (day-pday-1)*10;
        for(int j = i-1; j >= 0; j--){
            hours += saved[j];
        }
        int usedhours = 0;
        for(int j = 0; j < m; j++){
            int c;
            cin >> c;
            c--;
            if(!seen[c]){
                seen[c] = 1;
                usedhours += lengths[c];
            }
        }
        if(usedhours > hours){
            cout << "Nej" << endl;
            return 0;
        }
        saved[i] = (day-pday-1)*10-usedhours;
        pday = day;
    }
    cout << "Ja" << endl;
}
