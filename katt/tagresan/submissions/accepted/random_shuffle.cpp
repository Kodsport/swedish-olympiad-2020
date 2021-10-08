#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,T;
    cin >> T >> n >> m;
    vector<int> P;
    for(int c1 = 0; c1 < 4*n; c1++){
        P.push_back(c1+1);
    }
    random_shuffle(P.begin(), P.end());
    for(int c1 = 0; c1 < n; c1++){
        for(int c2 = 0; c2 < 4; c2++){
            cout << P[4*c1+c2] << " "; 
        }
        cout << "\n";
    }
    return 0;
}
