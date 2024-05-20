#include <bits/stdc++.h>
using namespace std;

int n,k;

int L[200001] = {0};
int kalas[2000011] = {0};
int earliest[200001] = {0};

vector<vector<int> > C(200001, vector<int>());

bool comp(int i, int j){
    return earliest[i] < earliest[j];
}

int main() {
    cin >> n >> k;
    vector<int> ind;
    for(int c1 = 0; c1 < k; c1++){
        cin >> L[c1];
        assert(L[c1] > 0);
        earliest[c1] = 1e9;
        ind.push_back(c1);
    }
    for(int c1 = 0; c1 < n; c1++){
        int a;
        cin >> a;
        a *= 10;
        for(int c2 = 0; c2 < 10; c2++){
            kalas[a+c2] = c1+1;
        }
        int b;
        cin >> b;
        for(int c2 = 0; c2 < b; c2++){
            int i;
            cin >> i;
            i--;
            C[c1].push_back(i);
            earliest[i] = min(earliest[i], a);
        }
    }
    sort(ind.begin(), ind.end(), comp);
    bool fail = 0;
    int current = 0;
    for(int t = 0; t < 2000011; t++){
        if(current == k)break;
        if(kalas[t] == 0){
            L[ind[current]]--;
            if(L[ind[current]] == 0)current++;
        }
        else{
            for(int c2 = 0; c2 < C[kalas[t]-1].size(); c2++){
                if(L[C[kalas[t]-1][c2]] != 0)fail = 1;
            }
            if(fail)break;
        }
    }
    if(fail){
        cout << "nej\n";
    }
    else{
        cout << "ja\n";
    }
    return 0;
}
