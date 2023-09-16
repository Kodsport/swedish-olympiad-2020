#include "validator.h"
#include <set>
using namespace std;

void run() {
	int nMax = Arg("nMax");
	int lMax = Arg("lMax");
    int kMax = Arg("kMax");

    string s1 = "";
    string s2 = "";
    int L1,L2;

    int k = Int(0, 1);
    assert(k <= kMax);
    Endl();

    char ch = Char();
    while(ch != ' '){
        s1 += ch;
        ch = Char();
    }

    L1 = Int(1, nMax);
    assert(L1 >= s1.length());
    Endl();

    ch = Char();
    while(ch != ' '){
        s2 += ch;
        ch = Char();
    }

    L2 = Int(1, nMax);
    assert(L2 >= s2.length());
    Endl();

    assert(s1.length() > 0);
    assert(s2.length() > 0);
    
    bool seen[26] = {0};
    int letters = 0;

    for(int c1 = 0; c1 < s1.length(); c1++){
        assert(s1[c1]-'a' >= 0 && s1[c1]-'a' < 26);
        if(!seen[s1[c1]-'a'])letters++;
        seen[s1[c1]-'a'] = 1;
    }
    for(int c1 = 0; c1 < s2.length(); c1++){
        assert(s2[c1]-'a' >= 0 && s2[c1]-'a' < 26);
        if(!seen[s2[c1]-'a'])letters++;
        seen[s2[c1]-'a'] = 1;
    }

    assert(letters <= lMax);
    for(int c1 = 0; c1 < 26; c1++){
        assert(c1 < lMax || !seen[c1]);
    }

}