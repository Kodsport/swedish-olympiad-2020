#include <bits/stdc++.h>
#include "validate.h"

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

void check_case(){
    int n,m,k;
    judge_in >> n >> m >> k;
    vector<vi> tree(n);
    rep(i, 0, n-1){
        int a,b;
        judge_in >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int author_first_integer;
    if(!(author_out >> author_first_integer)){
        wrong_answer("Could not read first integer of contestants output\n");
    }

    int judge_first_integer;
    if(!(judge_ans >> judge_first_integer)){
        judge_error("Could not read judge output\n");
    }

    if(author_first_integer == -1 && judge_first_integer == -1){
        return;
    }

    if (author_first_integer == -1) {
        wrong_answer("claimed no solution, but there is one\n");
    }
    // if judge_first_integer == -1 we'll get WA or JE below

    vector<int> author_answer;

    if(author_first_integer <= 0 || author_first_integer > n){
        wrong_answer("Contestants output was out of bounds\n");
    }
    author_answer.push_back(author_first_integer - 1);
    rep(c1, 0, m-1){
        int a;
        if(!(author_out >> a)){
            wrong_answer("Could not read contestants output\n");
        }
        if(a <= 0 || a > n){
            wrong_answer("Contestants output was out of bounds\n");
        }
        author_answer.push_back(a - 1);
    }
    
    if(author_answer.back() != k-1){
        wrong_answer("Last bird didn't land on node k\n");
    }

    vector<int> resident(n);
    vector<int> free_deg(n);
    vector<int> active; // stack of birds

    rep(c1, 0, n){
        resident[c1] = -1;
    }

    resident[author_answer[0]] = 0;
    free_deg[author_answer[0]] = sz(tree[author_answer[0]]);
    active.push_back(0);

    rep(c1, 1, m){
        int node = author_answer[c1];
        if(resident[node] != -1){
            wrong_answer("Two birds landed on top of each other\n");
        }
        while (!active.empty() && free_deg[author_answer[active.back()]] == 0){
            active.pop_back();
        }
        if (active.empty()){
            // the graph is connected and m <= n, so this should never happen
            judge_error("The birds ran out of space somehow\n");
        }
        int last = active.back();
        bool adj = 0;
        free_deg[node] = 0;
        trav(y, tree[node]){
            if(resident[y] == last)adj = 1;
            if(resident[y] == -1){
                free_deg[node]++;
            }
            else{
                free_deg[y]--;
            }
        }
        if(!adj){
            wrong_answer("A bird didn't land next to the latest possible\n");
        }
        resident[node] = c1;
        active.push_back(c1);
    }
    
    if(judge_first_integer == -1){
        judge_error("Contestant found a solution while judge didn't\n");
    }
}

int main(int argc, char **argv) {
  init_io(argc, argv);
  check_case();

  /* Check for trailing output. */
  string trash;
  if (author_out >> trash) {
      wrong_answer("Trailing output\n");
  }

  accept();
  return 0;
}
