#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;

struct Node {
	vector<int> edges;
	bool inAns = false;
};

vector<Node> nodes;
int remNodes;
int lastVisited;

void findAnsNodes(int n, int p) {
	remNodes--;
	lastVisited = n;
	nodes[n].inAns = true;
	for (int& e : nodes[n].edges) {
		if (e == p)
			swap(e, nodes[n].edges.back());
		if (e != p && remNodes > 0)
			findAnsNodes(e, n);
	}
}

void printAns(int n, int p) {
	cout << (n + 1) << " ";
	for (int e : nodes[n].edges) {
		if (e != p && nodes[e].inAns)
			printAns(e, n);
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	k--;
	
	nodes.resize(n);
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		nodes[a - 1].edges.push_back(b - 1);
		nodes[b - 1].edges.push_back(a - 1);
	}
	
	for (int root : nodes[k].edges) {
		remNodes = m - 1;
		findAnsNodes(root, k);
		if (remNodes == 0) {
			printAns(lastVisited, -1);
			cout << (k + 1) << "\n";
			return 0;
		}
	}
	
	cout << "-1\n";
}
