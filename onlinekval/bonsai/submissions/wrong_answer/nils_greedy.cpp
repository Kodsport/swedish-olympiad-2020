#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Some strange incorrect greedy that greedily grows the tree towards the subtrees with the most vertices.
// Only tries to solve the rooted versions.

vector<vector<int> > C(100001, vector<int>());
int n;

int SS[100001] = {0}; // subtree sizes
int DP[100001] = {0};

int dfs(int i, int par){
    int ans = 0;
    vector<pair<int,int> > subtrees;
    SS[i] = 1;
    for(int c1 = 0; c1 < C[i].size(); c1++){
        int a = C[i][c1];
        if(a != par){
            subtrees.push_back({SS[a], a});
            SS[i] += SS[a];
        }
    }
    sort(subtrees.begin(), subtrees.end());
    reverse(subtrees.begin(), subtrees.end());
    for(int c1 = 0; c1 < subtrees.size(); c1++){
        ans = max(ans, c1+1+DP[subtrees[c1].second]);
    }
    DP[i] = ans;
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
