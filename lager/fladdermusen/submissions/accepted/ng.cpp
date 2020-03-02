#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, b, a) for(int i = b - 1; i >= a; i--)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define hash dhsjakhd
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 eng(seed);

uniform_int_distribution<> DD(0, (1ll << 31));

ll random2(){
    return (ll(DD(eng))*(1ll << 31) + ll(DD(eng))) & ((1ll << 62ll)-1);
}

ll n,m,T,k,q;

const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;

const int MAXN = 400003;

struct pt{
    ll x,y;
};

vector<pt> P;
vi kind, ind;
vl ANS;
vector<pt> other;

bool comp(int i, int j){
    return P[i].x > P[j].x;
}

vi up,down;

int find_up(ll y){
    int l = 0;
    int r = sz(up);
    while(l < r-1){
        int mid = (l+r)/2;
        if(P[up[mid]].y < y){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return up[l];
}

int find_down(ll y){
    int l = 0;
    int r = sz(down);
    while(l < r-1){
        int mid = (l+r)/2;
        if(P[down[mid]].y > y){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return down[l];
}

const int lg = 19;
ll BL[MAXN][lg] = {0};
ll BW[MAXN][lg] = {0};

void give(int i, int par){
    BL[i][0] = par;
    BW[i][0] = abs(P[i].y - P[par].y);
    rep(c1,1,lg){
        BL[i][c1] = BL[BL[i][c1-1]][c1-1];
        BW[i][c1] = BW[i][c1-1] + BW[BL[i][c1-1]][c1-1];
    }
}

pll bl(int i, ll x){
    ll extra = 0;
    for(int step = lg-1; step >= 0; step--){
        if(P[BL[i][step]].x < x){
            extra += BW[i][step];
            i = BL[i][step];

        }
    }
    return {i, extra};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> n >> q >> a >> b;

    // 1 - down,  2 - up,  0 - bat

    rep(c1,0,n){
        ll x,y;
        cin >> a >> x >> y;
        P.push_back({x,y});
        ind.push_back(sz(ind));
        kind.push_back(a);
        ANS.push_back(-1);
        other.push_back({-1,-1});
    }
    rep(c1,0,q){
        ll x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if(x1 > x2){
            swap(x1,x2);
            swap(y1,y2);
        }
        P.push_back({x1,y1});
        ind.push_back(sz(ind));
        kind.push_back(0);
        ANS.push_back(0);
        other.push_back({x2,y2});
    }

    P.push_back({big+1,big});
    ind.push_back(sz(ind));
    kind.push_back(1);
    ANS.push_back(-1);
    other.push_back({-1,-1});

    P.push_back({big,-big});
    ind.push_back(sz(ind));
    kind.push_back(2);
    ANS.push_back(-1);
    other.push_back({-1,-1});

    sort(all(ind), comp);

    down.push_back(ind[0]);
    up.push_back(ind[1]);
    give(ind[0],ind[0]);
    give(ind[1],ind[1]);

    rep(c1,2,sz(ind)){
        int i = ind[c1];
        if(kind[i] == 1){
            int j1 = find_up(P[i].y);
            while(P[i].y > P[down.back()].y){
                down.pop_back();
            }
            int j2 = down.back();
            if(P[j1].x > P[j2].x)swap(j1,j2);
            give(i,j1);
            down.push_back(i);
        }
        if(kind[i] == 2){
            int j1 = find_down(P[i].y);
            while(P[i].y < P[up.back()].y){
                up.pop_back();
            }
            int j2 = up.back();
            if(P[j1].x > P[j2].x)swap(j1,j2);
            give(i,j1);
            up.push_back(i);
        }
        if(kind[i] == 0){
            ANS[i] = other[i].x - P[i].x;
            int j1 = find_up(P[i].y);
            int j2 = find_down(P[i].y);
            if(P[j1].x > P[j2].x)swap(j1,j2);
            if(other[i].x < P[j1].x){
                ANS[i] += abs(other[i].y - P[i].y);
            }
            else{
                ANS[i] += abs(P[i].y - P[j1].y);
                pll iw = bl(j1, other[i].x);
                ANS[i] += iw.second;
                ANS[i] += abs(P[iw.first].y - other[i].y);
            }
        }
    }

    rep(c1,0,sz(ind)){
        if(ANS[c1] != -1){
            cout << ANS[c1] << "\n";
        }
    }

    return 0;
}

