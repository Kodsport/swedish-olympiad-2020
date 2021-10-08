#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 500 * 1000 + 228;
const int MAX_NODE = MAX_N * 6;

struct node {
    int x;
    int value;
    int y;
    int sz;
    int min;
    int max;
    int l;
    int r;
};

node nodes[MAX_NODE];
int node_ptr = 0;

int new_node(int x, int value) {
    assert(node_ptr < MAX_NODE);
    nodes[node_ptr].x = x;
    nodes[node_ptr].value = value;
    nodes[node_ptr].y = ((rand() << 15) ^ rand());
    nodes[node_ptr].sz = 1;
    nodes[node_ptr].min = value;
    nodes[node_ptr].max = value;
    nodes[node_ptr].l = -1;
    nodes[node_ptr].r = -1;

    return node_ptr++;
}

int get_sz(int t) {
    if (t == -1) {
        return 0;
    }
    return nodes[t].sz;
}

int get_min(int t) {
    if (t == -1) {
        return INF;
    }
    return nodes[t].min;
}

int get_max(int t) {
    if (t == -1) {
        return -INF;
    }
    return nodes[t].max;
}

void calc(int t) {
    if (t != -1) {
        nodes[t].sz = 1 + get_sz(nodes[t].l) + get_sz(nodes[t].r);
        nodes[t].min = min(nodes[t].value, min(get_min(nodes[t].l), get_min(nodes[t].r)));
        nodes[t].max = max(nodes[t].value, max(get_max(nodes[t].l), get_max(nodes[t].r)));
    }
}

int merge(int t1, int t2) {
    if (t1 == -1) {
        return t2;
    }
    if (t2 == -1) {
        return t1;
    }

    if (nodes[t1].y < nodes[t2].y) {
        nodes[t1].r = merge(nodes[t1].r, t2);
        calc(t1);
        return t1;
    } else {
        nodes[t2].l = merge(t1, nodes[t2].l);
        calc(t2);
        return t2;
    }
}

void split(int t, int& t1, int& t2, int x) {
    if (t == -1) {
        t1 = -1;
        t2 = -1;
        return;
    }

    if (nodes[t].x < x) {
        split(nodes[t].r, nodes[t].r, t2, x);
        t1 = t;
    } else {
        split(nodes[t].l, t1, nodes[t].l, x);
        t2 = t;
    }

    calc(t);
}

struct tree {
    map<int, int> t_at;
    int tree;

    void build(int _sz) {
        ++_sz;
        tree = -1;
    }

    int tree_find_left_alive(int t, int time) {
        if (t == -1) {
            return INF;
        }

        int ans = INF;
        if (nodes[t].value >= time) {
            ans = nodes[t].x;
        }

        if (get_max(nodes[t].l) >= time) {
            return min(ans, tree_find_left_alive(nodes[t].l, time));
        } else if (get_max(nodes[t].r) >= time) {
            return min(ans, tree_find_left_alive(nodes[t].r, time));
        } else {
            return ans;
        }
    }

    int tree_find_right_alive(int t, int time) {
         if (t == -1) {
            return -1;
        }

        int ans = -1;
        if (nodes[t].value >= time) {
            ans = nodes[t].x;
        }

        if (get_max(nodes[t].r) >= time) {
            return max(ans, tree_find_right_alive(nodes[t].r, time));
        } else if (get_max(nodes[t].l) >= time) {
            return max(ans, tree_find_right_alive(nodes[t].l, time));
        } else {
            return ans;
        }
    }

    bool is_alive(int x, int t) {
        if (t_at.find(x) != t_at.end()) {
            return t_at[x] >= t;
        }
        return false;
    }

    int find_left_alive(int x, int t) {
        int t1, t2;
        split(tree, t1, t2, x + 1);
        int ptr = tree_find_right_alive(t1, t);
        tree = merge(t1, t2);
        return ptr;
    }

    int find_right_alive(int x, int t) {
        int t1, t2;
        split(tree, t1, t2, x);
        int ptr = tree_find_left_alive(t2, t);
        tree = merge(t1, t2);
        return ptr == INF ? -1 : ptr;
    }

    bool alive_range(int l, int r, int t) {
        if (l > r) {
            swap(l, r);
        }
        int t1, t2, t3, t4;
        split(tree, t1, t2, l);
        split(t2, t3, t4, r + 1);
        bool ans = (get_sz(t3) == r - l + 1 && get_min(t3) >= t);
        tree = merge(merge(t1, t3), t4);
        return ans;
    }

    void set_t(int x, int t) {
        t_at[x] = t;
        int t1, t2, t3, t4;
        split(tree, t1, t2, x);
        split(t2, t3, t4, x + 1);
        tree = merge(merge(t1, new_node(x, t)), t4);
    }
};

int n, m, q;
tree row_tree;
tree col_tree;

int get(int x1, int y1, int x2, int y2, int cur_snow, int k) {
    int t = cur_snow - k;

    if (t <= 0) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    if (!row_tree.is_alive(x1, t) && !col_tree.is_alive(y1, t)) {
        return INF;
    }
    if (!row_tree.is_alive(x2, t) && !col_tree.is_alive(y2, t)) {
        return INF;
    }

    if (row_tree.alive_range(x1, x2, t) || col_tree.alive_range(y1, y2, t)) {
        return abs(x1 - x2) + abs(y1 - y2);
    }

    int ans = INF;

    vector<int> row1 = {
        row_tree.find_left_alive(x1, t),
        row_tree.find_right_alive(x1, t)
    };
    vector<int> col1 = {
        col_tree.find_left_alive(y1, t),
        col_tree.find_right_alive(y1, t)
    };
    vector<int> row2 = {
        row_tree.find_left_alive(x2, t),
        row_tree.find_right_alive(x2, t)
    };
    vector<int> col2 = {
        col_tree.find_left_alive(y2, t),
        col_tree.find_right_alive(y2, t)
    };

    for (int nx1 : row1) {
        for (int ny1 : col1) {
            for (int nx2 : row2) {
                for (int ny2 : col2) {
                    if (nx1 != -1 && ny1 != -1 && nx2 != -1 && ny2 != -1) {
                        int cur_dist =
                            abs(nx1 - nx2)
                            + abs(ny1 - ny2)
                            + abs(x1 - nx1)
                            + abs(y1 - ny1)
                            + abs(x2 - nx2)
                            + abs(y2 - ny2);
                        ans = min(ans, cur_dist);
                    }
                }
            }
        }
    }

    return ans;
}

int main() {
#ifdef CH_EGOR
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen("", "r", stdin);
    //freopen("", "w", stdout);
#endif

    srand(228);

    scanf("%d%d%d", &n, &m, &q);
    row_tree.build(n);
    col_tree.build(m);

    for (int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);

        if (type == 1 || type == 2) {
            int cur;
            scanf("%d", &cur);
            --cur;

            if (type == 1) {
                row_tree.set_t(cur, i + 1);
            } else {
                col_tree.set_t(cur, i + 1);
            }

        } else {
            int x1, y1, x2, y2, k;
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
            --x1; --y1; --x2; --y2;

            int ans = get(x1, y1, x2, y2, i + 1, k);

            if (ans != INF) {
                printf("%d\n", ans);
            } else {
                printf("-1\n");
            }
        }
    }

    return 0;
}