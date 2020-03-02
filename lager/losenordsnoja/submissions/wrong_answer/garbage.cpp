#include <bits/stdc++.h>
using namespace std;

const int MAXN = 201;


int main() {
    string s1,s2;
    int l1,l2;
    cin >> s1 >> l1 >> s2 >> l2;

    string alfa = "abcdefghijklmnopqrstuvwxyz<";

    for(int c1 = 0; c1 < 100000; c1++){
        cout << char(rand()%200);
    }cout << "\n";

    return 0;
}

