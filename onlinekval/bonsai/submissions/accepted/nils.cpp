#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int> > C(100001, vector<int>());
int n;

unordered_map<ll,int> M;

vector<vector<int> > pref(100001, vector<int>());
vector<vector<int> > suff(100001, vector<int>());
vector<vector<int> > part(100001, vector<int>());

vector<map<int,int> > where(100001, map<int,int>());

int processed[100001] = {0};

void process(int i){
    processed[i] = 2;
    vector<pair<int,int> > parts;
    for(int c1 = 0; c1 < C[i].size(); c1++){
        int a = C[i][c1];
        parts.push_back({part[i][c1], a});
    }
    sort(parts.begin(), parts.end());
    int ma = 0;
    int ps = parts.size();
    for(int c1 = 0; c1 < ps; c1++){
        pref[i][c1] = ma;
        ma = max(ma, parts[c1].first + ps - c1);
        where[i][parts[c1].second] = c1;
    }
    ma = 0;
    for(int c2 = 0; c2 < ps; c2++){
        int c1 = ps - c2 - 1;
        suff[i][c1] = ma;
        ma = max(ma, parts[c1].first + ps - c1);
    }
}

queue<int> Q;

int dfs(int i, int par){
    ll h = (ll)i * (n + 1) + par + 1;
    if(M.find(h) != M.end())return M[h];
    if(processed[i] == 2 && par != -1){
        int w = where[i][par];
        return max(pref[i][w]-1, suff[i][w]);
    }
    int ans = 0;
    vector<int> subtrees;
    bool good = 1;
    for(int c1 = 0; c1 < C[i].size(); c1++){
        int a = C[i][c1];
        if(a != par){
            subtrees.push_back(dfs(a,i));
            part[i][c1] = subtrees.back();
        }
        if(part[i][c1] == -1)good = 0;
    }
    if(good && !processed[i]){
        processed[i] = 1;
        Q.push(i);
    }
    sort(subtrees.begin(), subtrees.end());
    reverse(subtrees.begin(), subtrees.end());
    for(int c1 = 0; c1 < subtrees.size(); c1++){
        ans = max(ans, c1+1+subtrees[c1]);
    }
    M[h] = ans;
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
            pref[c1].push_back(0);
            suff[c1].push_back(0);
            part[c1].push_back(-1);
        }
    }
    int ans = n;
    for(int c1 = 0; c1 < n; c1++){
        ans = min(ans, dfs(c1,-1));
        while(!Q.empty()){
            process(Q.front());
            Q.pop();
        }
    }
    cout << ans << "\n";
    return 0;
}
