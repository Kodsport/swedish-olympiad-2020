#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    int height[11][11] = {0};
    cin >> n >> m;
    for(int c1 = 0; c1 < n; c1++){
        string s;
        cin >> s;
        for(int c2 = 0; c2 < m; c2++){
            if(s[c2] == '.'){
                height[c1][c2] = -1;
            }
            else{
                height[c1][c2] = s[c2]-'0';
            }
        }
    }    
    for(int x1 = 0; x1 < n; x1++){
        for(int y1 = 0; y1 < m; y1++){
            int mi = 0;
            int ma = 9;
            for(int x2 = 0; x2 < n; x2++){
                for(int y2 = 0; y2 < m; y2++){
                    if(height[x2][y2] != -1){
                        mi = max(mi, height[x2][y2] - abs(x2-x1) - abs(y2-y1));
                        ma = min(ma, height[x2][y2] + abs(x2-x1) + abs(y2-y1));
                    }
                }
            }
            assert(mi <= ma);
            if(mi == ma){
                height[x1][y1] = mi;
                cout << height[x1][y1];
            }
            else{
                cout << '.';
            }
        }
        cout << "\n";
    }
    return 0;
}
