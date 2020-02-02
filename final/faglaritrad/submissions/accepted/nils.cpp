#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;
int n,m,k;
vector<vector<int> > tree(MAXN, vector<int>());
int latest[MAXN] = {0};
vector<int> answer;
int t = 0;

void dfs(int i, int par){
    t++;
    latest[i] = t;
    answer.push_back(i);
    if((int)answer.size() == m-1)return;
    for(int c1 = 0; c1 < (int)tree[i].size(); c1++){
        int a = tree[i][c1];
        if(a != par){
            dfs(a,i);
            if((int)answer.size() == m-1)return;
            t++;
            latest[i] = t;
        }
    }
}


bool post_order(int i, int j){
    return latest[i] > latest[j];
}

int main() {
    cin >> n >> m >> k;
    k--;
    for(int c1 = 0; c1 < n-1; c1++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    for(int c1 = 0; c1 < (int)tree[k].size(); c1++){
        answer.clear();
        dfs(tree[k][c1],k);
        if((int)answer.size() == m-1){
            sort(answer.begin(), answer.end(), post_order);
            for(int c2 = 0; c2 < m-1; c2++){
                cout << answer[c2]+1 << " ";
            }
            cout << k+1 << "\n";
            return 0;
        }
    }
    cout << "-1\n";
    return 0;
}
