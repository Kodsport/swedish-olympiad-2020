#include <bits/stdc++.h>
using namespace std;

struct Node {
	unordered_set<int> edges;
	stack<int> leafEdges;
};

int main() {
	int n;
	cin >> n;
	
	vector<Node> nodes(n);
	vector<int> hasLeaf, nextHasLeaf;
	
	for (int i = 0; i < n; i++) {
		int m; cin >> m;
		for (int j = 0; j < m; j++) {
			int e;
			cin >> e;
			nodes[i].edges.insert(e);
			if (m == 1) {
				if (nodes[e].leafEdges.empty())
					hasLeaf.push_back(e);
				nodes[e].leafEdges.push(i);
			}
		}
	}
	
	int ans = 0;
	while (!hasLeaf.empty()) {
		nextHasLeaf.clear();
		for (int node : hasLeaf) {
			int leaf = nodes[node].leafEdges.top();
			nodes[node].leafEdges.pop();
			nodes[node].edges.erase(leaf);
			
			if (nodes[node].edges.size() == 1) {
				int par = *nodes[node].edges.begin();
				if (nodes[par].leafEdges.empty())
					nextHasLeaf.push_back(par);
				nodes[par].leafEdges.push(node);
			}
			
			if (!nodes[node].leafEdges.empty())
				nextHasLeaf.push_back(node);
		}
		hasLeaf.swap(nextHasLeaf);
		ans++;
	}
	
	cout << ans << "\n";
}
