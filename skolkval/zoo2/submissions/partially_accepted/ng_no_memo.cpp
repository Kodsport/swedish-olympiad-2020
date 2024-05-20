#include <bits/stdc++.h>
using namespace std;

bool bad[11][11] = {0};
int DP[16][11] = {0};
bool DPC[16][11] = {0};

int n,k,m;

int dp(int i, int last){
    if(i == n)return 1;
    //if(DPC[i][last])return DP[i][last];
    DP[i][last] = 0;
    for(int c1 = 0; c1 < k; c1++){
        if(!bad[c1][last])DP[i][last]+= dp(i+1, c1);
    }
    DPC[i][last] = 1;
    return DP[i][last];
}

int main() {
    cin >> n >> k >> m;
    for(int c1 = 0; c1 < k; c1++){
        bad[c1][c1] = 1;
    }
    for(int c1 = 0; c1 < m; c1++){
        string s;
        cin >> s;
        for(int c2 = 0; c2 < s.length(); c2++){
            for(int c3 = 0; c3 < s.length(); c3++){
                bad[s[c2]-'A'][s[c3]-'A'] = 1;
            }
        }
    }

    cout << dp(0,k) << "\n";
    return 0;
}
