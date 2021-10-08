#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    string consonants = "bcdfghjklmnpqrstvwxz";
    bool C[26] = {0};
    for(int c1 = 0; c1 < consonants.length(); c1++){
        C[consonants[c1]-'a'] = 1;
    }
    while(cin >> s){
        string ans = "";
        ans += s[0];
        ans += s[1];
        for(int c1 = 2; c1 < s.length(); c1++){
            if(C[s[c1]-'a']){
                if(!(s[c1] == s[c1-1] && s[c1] == s[c1-2])){
                    ans += s[c1];
                }
            }
            else{
                ans += s[c1];
            }
        }
        cout << ans << " ";
    }cout << "\n";
    return 0;
}
