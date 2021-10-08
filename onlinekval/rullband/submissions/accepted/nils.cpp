#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,g;
    vector<vector<int> > graph(200001, vector<int>());
    vector<vector<int> > W(200001, vector<int>());
    int dist[200001] = {0};
    bool mark[200001] = {0};
    cin >> n >> m >> g;
    for(int c1 = 0; c1 < n; c1++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        W[a].push_back(c);
    }
    for(int c1 = 1; c1 <= m; c1++){
        graph[c1].push_back(c1-1);
        graph[c1-1].push_back(c1);
        W[c1].push_back(g);
        W[c1-1].push_back(g);
        dist[c1] = 1e9;
    }
    priority_queue<pair<int,int> > pq;
    pq.push({0,0});
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(!mark[a]){
            mark[a] = 1;
            for(int c1 = 0; c1 < graph[a].size(); c1++){
                int b = graph[a][c1];
                int w = W[a][c1];
                if(dist[a] + w < dist[b]){
                    dist[b] = dist[a] + w;
                    pq.push({-dist[b],b});
                }
            }
        }
    } 
    cout << dist[m] << "\n";
    return 0;
}
