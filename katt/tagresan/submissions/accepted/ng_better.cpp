#pragma GCC optimize("O3")   //
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

const int MAXN = 100001;

int N;

set<ll> E;
vector<vi> C(MAXN, vi());

bool inbounds(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < 4;
}

struct solution{
    vl X,Y;
    vector<double> sc;
    solution(int n) : X(n), Y(n), sc(n) {}
};

int score_counter = 0;

double ind_score(solution &sol, int i){
    sol.sc[i] = 0.0;
    trav(j, C[i]){  
        sol.sc[i] += 1.0 / double((sol.X[i] - sol.X[j]) * (sol.X[i] - sol.X[j])  + (sol.Y[i] - sol.Y[j]) * (sol.Y[i] - sol.Y[j]));
        score_counter++;
    }
    return sol.sc[i];
}

double score(solution &sol){
    double res = 0;
    rep(i,0,4*n){
        res += ind_score(sol, i);
    }
    return res;
}


int I[MAXN][4] = {0};
void setup_I(solution &sol){
    rep(c1,0,sz(sol.X)){
        I[sol.X[c1]][sol.Y[c1]] = c1;
    }
}


void print_solution(solution &sol){
    setup_I(sol);
    rep(c1,0,n){
        rep(c2,0,4){
            cout << I[c1][c2]+1 << " ";
        }
        cout << "\n";
    }
}

vector<pii> snake_sort(){
    vector<pii> res;
    rep(c1,0,n){
        rep(c3,0,4){
            int c2 = c3;
            if(c1%2 == 1)c2 = 3-c3;
            res.push_back({c1,c2});
        }
    }
    return res;
}

vector<pii> zigzag(){
    vector<pii> res;
    rep(c1,0,n){
        res.push_back({c1,c1%2});
        res.push_back({c1,(c1+1)%2});
    }
    rep(c1,0,n){
        res.push_back({n-1-c1,c1%2+2});
        res.push_back({n-1-c1,(c1+1)%2+2});
    }
    return res;
}

void one_swap(solution &sol){
    int i = rand()%N;
    int x = sol.X[i];
    int y = sol.Y[i];
    int dx = rand()%7-3;
    int dy = rand()%7-3;
    while((dx == 0 && dy == 0) || !inbounds(x+dx, y+dy)){
        dx = rand()%7-3;
        dy = rand()%7-3;
    }
    int j = I[x+dx][y+dy];

    double old_score = ind_score(sol, i) + ind_score(sol, j);
    swap(sol.X[i], sol.X[j]); swap(sol.Y[i], sol.Y[j]);
    double new_score = ind_score(sol, i) + ind_score(sol, j);
    if(new_score <= old_score){
        swap(sol.X[i], sol.X[j]); swap(sol.Y[i], sol.Y[j]);
    }
    I[sol.X[i]][sol.Y[i]] = i;
    I[sol.X[j]][sol.Y[j]] = j;
 
}

set<ll> people;
int get_next(int prev){
    if(prev == -1){
        return *(people.begin());
    }
    int a = *(people.begin());
    trav(y, C[prev]){
        if(people.find(y) != people.end())a = y;
    }
    return a;
}

solution greedy1(){
    rep(c1,0,N){
        people.insert(c1);
    }
    solution res(N);
    ll prev = -1;
    for(int c1 = 0; c1 < n; c1++){
        for(int c3 = 0; c3 < 4; c3++){
            int c2 = c3;
            if(c1%2 == 1)c2 = 3-c3;
            int a = get_next(prev);
            people.erase(a);
            res.X[a] = c1;
            res.Y[a] = c2;
            prev = a;
        }
    }
    return res;
}

solution greedy2(){
    solution res(N);
    rep(i,0,N){
        res.X[i] = -big;
        res.Y[i] = -big;
    }
    rep(c1,0,n){
        rep(c2,0,4){
            int person = -1;
            double best = -1;
            rep(c3,0,N){
                if(res.X[c3] == -big){
                    double temp = 0.0;
                    trav(j, C[c3]){
                        if(res.X[j] != -big){
                            temp += 1.0 / double((ll(c1) - res.X[j]) * (ll(c1) - res.X[j])  + (ll(c2) - res.Y[j]) * (ll(c2) - res.Y[j]));
                        }
                    }
                    if(temp > best){
                        best = temp;
                        person = c3;
                    }
                }
            }
            res.X[person] = c1;
            res.Y[person] = c2;
        }
    }
    return res;
}



solution greedy3(int mode, int suff){
    people.clear();
    bool taken[4*MAXN] = {0};
    rep(c1,0,N){
        people.insert(c1);
    }
    double temp_score[4*MAXN] = {0};
    int last_update[MAXN * 4] = {0};
    int cc = 0;
    vi order;
    solution res(N);
    vector<pii> points;
    if(mode == 0)points = snake_sort();
    if(mode == 1)points = zigzag();
    trav(p, points){
        int c1 = p.first;
        int c2 = p.second;
        int person = *(people.begin());
        double best_score = -1;
        vi candidates;
        cc++;
            
        for(int i = sz(order)-1; i >= max(0, sz(order)-suff); i--){
            trav(j, C[order[i]]){
                if(!taken[j]){
                        
                    double dx = c1 - res.X[order[i]];
                    double dy = c2 - res.Y[order[i]];
                    double temp = 1.0 / (dx*dx + dy*dy);
                        
                    if(last_update[j] != cc){
                        last_update[j] = cc;
                        temp_score[j] = 0;
                        candidates.push_back(j);
                    }
                    temp_score[j] += temp;
                }
            }
        }
            
        trav(c, candidates){   
            if(temp_score[c] > best_score){
                best_score = temp_score[c];
                person = c;
            }            
        }

        people.erase(person);
        res.X[person] = c1;
        res.Y[person] = c2;
        taken[person] = 1;
        order.push_back(person);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d,e;

    cin >> T;
    cin >> n >> m;
    N = 4*n;

    rep(c1,0,m){
        cin >> a >> b;
        a--;
        b--;
        E.insert(a*4*n+b);
        E.insert(b*4*n+a);
        C[a].push_back(b);
        C[b].push_back(a);
    }


    //////
    /*
    solution sol2 = greedy1();
    cerr << score(sol2) << "   -  1\n";
    if(N*m < 20000000)sol2 = greedy2();
    if(N*m < 20000000)cerr << score(sol2) << "   -  2\n";
    sol2 = greedy3();
    cerr << score(sol2) << "   -  3\n";

    return 0;
    */
    //////

    int mode = 0;
    int suff = 50;
    if(T == 3)suff = 200;

    solution sol = greedy3(mode, suff);
    if(N*m <= 20000000){
        solution sol2 = greedy2();
        if(score(sol2) > score(sol)){
            sol = sol2;
        }
    }

    if(T == 4){
        solution sol3 = greedy3(1, suff);
        if(score(sol3) > score(sol)){
            sol = sol3;
        }
    }

    cerr << score(sol) << "\n";
    setup_I(sol);

    while(score_counter < 20000000){
        one_swap(sol);
    }
    cerr << score(sol) << ": " << T << "\n";
    print_solution(sol);

    return 0;
}

