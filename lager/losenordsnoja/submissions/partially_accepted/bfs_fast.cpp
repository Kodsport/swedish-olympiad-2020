#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 2001;

struct state{
    int i1, g1, i2, g2;
};

ll has(state s){
    return ((s.i1*MAXN + s.g1)*MAXN + s.i2)*MAXN + s.g2;
}

void prnt(state s){
    cerr << s.i1 << " " << s.g1 << "  -  " << s.i2 << " " << s.g2 << "\n";
}

string s1,s2;
int l1,l2;

state new_state(state old, char ch){
    state res = old;
    if(ch == '<'){
        if(res.g1 > 0){
            res.g1--;
        }
        else{
            if(res.i1 > 0)res.i1--;
        }
        if(res.g2 > 0){
            res.g2--;
        }
        else{
            if(res.i2 > 0)res.i2--;
        }
        return res;
    }
    if(res.g1 == 0 && ((res.i1 < s1.length() && ch == s1[res.i1]) || (res.i1 >= s1.length() && res.i2 == s2.length()))){
        if(res.i1 < l1)res.i1++;
    }
    else{
        if(res.g1 + res.i1 < l1)res.g1++;
    }
    if(res.g2 == 0 && res.i2 < s2.length() && ch == s2[res.i2]){
        if(res.i2 < l2)res.i2++;
    }
    else{
        if(res.g2 + res.i2 < l2)res.g2++;
    }
    return res;
}

map<ll,int> M;
vector<state> VS;
vector<int> parent;
vector<char> CH;
vector<int> dist;
vector<bool> done;

void set_state(state s, int par, char ch, int d){
    ll h = has(s);
    M[h] = (int)VS.size();
    VS.push_back(s);
    parent.push_back(par);
    CH.push_back(ch);
    dist.push_back(d);
    done.push_back(0);
}

void bfs(){
    queue<int> Q;
    Q.push(0);
    set_state({0,0,0,0}, -1, 'X', 0);
    while(!Q.empty()){
        int i = Q.front();
        Q.pop();
        //prnt(VS[i]);
        //if(VS.size() % 100 == 0){
         //   cerr << VS.size() << "\n";
        //}
        if(!done[i]){
            done[i] = 1;
            int x1 = VS[i].i1 + VS[i].g1;
            int x2 = VS[i].i2 + VS[i].g2;
            vector<char> moves;
            moves.push_back('<');
            if(x1 < s1.length()){
                moves.push_back(s1[x1]);
            }
            //if(x2 < s2.length()){
             //   moves.push_back(s2[x2]);
           // }
            if(x1 >= s1.length() && x2 >= s2.length()){
                moves.push_back('z');
            }
            for(char ch : moves){
                state s2 = new_state(VS[i], ch);
                ll h = has(s2);
                if(M.find(h) == M.end()){
                    Q.push(VS.size());
                    set_state(s2, i, ch, dist[i] + 1);
                }
            }
        }
    }
}

int main() {
    int k;
    cin >> k;
    cin >> s1 >> l1 >> s2 >> l2;
//    if(max(l1,l2) > 300 && k == 0)return 0;
    if(l1 < l2){
        swap(s1,s2);
        swap(l1,l2);
    }
    bfs();
    ll h = has({s1.length(), 0, s2.length(), 0});
    if(M.find(h) == M.end()){
        cout << "!\n";
    }
    else{
        string ans = "";
        int i = M[h];
        while(i != 0){
            ans += CH[i];
            i = parent[i];
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}

