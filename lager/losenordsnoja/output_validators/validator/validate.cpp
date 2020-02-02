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

const int MAX_ANSWER = 1000000;

string text(string seq, int L){
    string res = "";
    rep(c1,0,seq.length()){
        if(seq[c1] == '<'){
            if(res.length() > 0)res.pop_back();
        }
        else{
            if(res.length() < L)res += seq[c1];
        }
    }
    return res;
}

bool valid_answer(string s){
    if(s.length() == 0)return 0;
    if(s.length() > MAX_ANSWER)return 0;
    rep(c1,0,s.length()){
        if(s[c1]-'a' < 0 || s[c1]-'a' >= 26){
            if(s[c1] != '!'){
                if(s[c1] != '<')return 0;
            }
            else{
                if(s.length() != 1)return 0;
            }
        }
    }
    return 1;
}

void check_case(){
    string s1,s2;
    int L1,L2;
    int k;
    judge_in >> k;
    judge_in >> s1 >> L1;
    judge_in >> s2 >> L2;

    string judge_answer, author_answer;

    if(!(author_out >> author_answer)){
        wrong_answer("Could not read contestants output\n");
    }
    if(!(judge_ans >> judge_answer)){
        judge_error("Could not read judge output\n");
    }
    if(!valid_answer(author_answer)){
        wrong_answer("Contestants output was not valid\n");
    }

    if(author_answer == "!"){
        if(judge_answer != "!"){
            wrong_answer("Contestant says impossible, but it is possible\n");
        }
        return;
    }
    
    if(text(author_answer, L1) != s1){
        wrong_answer("Contestants answer doesn't work on the first string\n");
    }
    if(text(author_answer, L2) != s2){
        wrong_answer("Contestants answer doesn't work on the second string\n");
    }
    
    if(judge_answer == "!"){
        judge_error("Judge says impossible, but contestant found a solution\n");
    }

    if(k == 1){
        if((int)author_answer.length() > (int)judge_answer.length()){
            wrong_answer("Contestants answer was valid but not shortest possible\n");
        }
        if((int)author_answer.length() < (int)judge_answer.length()){
            judge_error("Contestant found a shorter solution than judges\n");
        }
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