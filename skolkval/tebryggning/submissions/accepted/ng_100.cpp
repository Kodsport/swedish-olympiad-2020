#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> k >> n;
    vector<int> X;
    for(int c1 = 0; c1 < k; c1++){
        int x;
        cin >> x;
        while(x >= 10){
            X.push_back(10);
            x -= 10;
        }
        X.push_back(x);
    }
    sort(X.begin(), X.end());
    reverse(X.begin(), X.end());

    int ans = 0;
    while(n > 0){
        n -= X[ans];
        ans++;
    }

    cout << ans << "\n";
    return 0;
}
