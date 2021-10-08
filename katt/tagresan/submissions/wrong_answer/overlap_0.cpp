#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,T;
    cin >> T >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            cout << rand()%(4*n-1) + 1 << " "; 
        }
        cout << "\n";
    }
    return 0;
}
