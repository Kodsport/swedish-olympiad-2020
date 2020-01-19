#include "validator.h"

void assertBinaryString(const string& s) {
    for (char c : s) assert(c == '1' || c == '0');
}

void run() {
    int maxK = Arg("k");
    int maxN = Arg("maxN");
    int maxQ = Arg("maxQ");

    int n = Int(1, maxN);
    Space();
    int k = Int(1, maxK);
    Endl();

    set<string> seen;
    for (int i = 0; i < n; ++i) {
        string line = Line();
        seen.insert(line);
        assertBinaryString(line);
        assert((int)line.size() == k);
    }
    assert((int)seen.size() == n);

    int q = Int(1, maxQ);
    Endl();
    for (int i = 0; i < q; ++i) {
        string line = Line();
        assertBinaryString(line);
        assert((int)line.size() == k);
    }
}
