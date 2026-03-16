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

void give_answer(int i, int ans){
    if(answer[i] != 0 && ans != answer[i])fail = 1;
    if(answer[i] != 0)return;
    answer[i] = ans;
    if(i%2 == 0){
        if(i < n-1)give_answer(i+1, ((ans-1)^1)+1);
    }
    else{
        give_answer(i-1, ((ans-1)^1)+1);
    }
    if(color[i] != -1)give_answer(color[i], ans);
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
        if(answer[c1] == 0)give_answer(c1, 1);
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


