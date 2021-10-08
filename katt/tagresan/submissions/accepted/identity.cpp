#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,T;
    cin >> T >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            cout << 4*c1+1+c2 << " "; 
        }
        cout << "\n";
    }
    return 0;
}
