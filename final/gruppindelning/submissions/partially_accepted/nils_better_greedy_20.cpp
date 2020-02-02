#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

const int MAXN = 100000;

int n,m;

int answer[MAXN] = {0};
int color[MAXN] = {0};

bool fail = 0;

void give_answer(int i, int col){
    if(answer[i] != 0 && col != answer[i])fail = 1;
    answer[i] = col;
}

int main() {
    
    cin >> n >> m;
    rep(c1,0,n){
        color[c1] = -1;
    }
    rep(c1,0,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        color[a] = b;
        color[b] = a;
    }
    
    rep(c1,0,n){
        if(answer[c1] == 0){
            if(c1 < n-1 && c1%2 == 0 && answer[c1+1] != 0)give_answer(c1, ((answer[c1+1]-1)^1)+1);
            give_answer(c1, 1);
        }
        if(c1%2 == 0 && c1 < n-1)give_answer(c1+1, ((answer[c1]-1)^1)+1);
        if(color[c1] != -1)give_answer(color[c1], answer[c1]);
    }

    if(fail){
        cout << "-1\n";
    }
    else{
        rep(c1,0,n){cout << answer[c1];}
        cout << "\n";
    }

    return 0;
}


