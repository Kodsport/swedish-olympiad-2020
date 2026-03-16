#include "validator.h"

void run() {
    int n = Int(1, Arg("n"));
    Space();
    int m = Int(0, n/2);
    Endl();
    vector<int> m_map(n);
    bool consecutive = Arg("consecutive", 0);
    for (int i = 0; i < m; i++) {
        int a = Int(1, n);
        Space();
        int b = Int(1, n);
        Endl();
        a--, b--;
        if (consecutive) {
            assert(a == b + 1 || a == b - 1);
        }
        assert(m_map[a] != 1);
        m_map[a] = 1;
        assert(m_map[b] != 1);
        m_map[b] = 1;
    }
}
