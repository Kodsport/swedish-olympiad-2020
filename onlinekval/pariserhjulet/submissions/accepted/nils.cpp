#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n,m;
    cin >> n >> m;
    priority_queue<ll> pq;
    for(int c1 = 0; c1 < m; c1++){
        pq.push(-c1);
    }
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ll a;
        cin >> a;
        ll t = -pq.top();
        pq.pop();
        ans = max(ans, t+m*a);
        pq.push(-(t+m*a));
    }
    cout << ans << "\n";
    return 0;
}
