#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> > C(100001, vector<int>());
int n;

int dfs(int i, int par){
    int ans = 0;
    vector<int> subtrees;
    for(int c1 = 0; c1 < C[i].size(); c1++){
        int a = C[i][c1];
        if(a != par){
            subtrees.push_back(dfs(a,i));
        }
    }
    sort(subtrees.begin(), subtrees.end());
    reverse(subtrees.begin(), subtrees.end());
    for(int c1 = 0; c1 < subtrees.size(); c1++){
        ans = max(ans, c1+1+subtrees[c1]);
    }
    return ans;
}

int main() {
    cin >> n;
    for(int c1 = 0; c1 < n; c1++){
        int a;
        cin >> a;
        for(int c2 = 0; c2 < a; c2++){
            int b;
            cin >> b;
            C[c1].push_back(b);
        }
    }
    cout << dfs(0,-1) << "\n";
    return 0;
}

