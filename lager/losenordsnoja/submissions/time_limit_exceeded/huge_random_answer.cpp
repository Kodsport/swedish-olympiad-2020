#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2001;


int main() {
    string s1,s2;
    int l1,l2;
    int k;
    cin >> k;
    cin >> s1 >> l1 >> s2 >> l2;

    string alfa = "abcdefghijklmnopqrstuvwxyz<";

    for(int c1 = 0; c1 < 1000000000; c1++){
        cout << alfa[rand()%27];
    }cout << "\n";

    return 0;
}

