#include <bits/stdc++.h>
#include "validator.h"

using namespace std;

vector<vector<int>> tree;
int n,m,k;

bool connected() {
    queue<int> Q;
	vector<bool> mark(n);
    Q.push(0);
    int seen = 0;
    while (!Q.empty()) {
        int a = Q.front();
        Q.pop();
        if (!mark[a]) {
            mark[a] = 1;
            seen++;
			for (int b : tree[a]) {
                Q.push(b);
            }
        }
    }
    return (seen == n);
}

void run() {
	int nMax = Arg("nMax");

	n = Int(2, nMax);
    Space();
    m = Int(2, n);
    Space();
    k = Int(1, n);
	Endl();

	tree.resize(n);
	for (int i = 0; i < n-1; i++) {
        int u = Int(1, n);
        Space();
        int v = Int(1, n);
        Endl();
        tree[u-1].push_back(v-1);
        tree[v-1].push_back(u-1);
    }

    assert(connected());
}
