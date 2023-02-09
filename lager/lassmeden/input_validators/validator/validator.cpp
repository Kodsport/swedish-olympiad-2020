#include "validator.h"
#include <map>
#include <set>

void run(){
    int nMax = Arg("nMax");
    int qMax = Arg("qMax");
    int N = Int(1,nMax);
    Space();
    int Q = Int(1,qMax);
    Endl();
    
    int num_query1 = 0;
    map<pair<int,int>,int> keys;
    for(int i = 0; i < Q; i++){
        int op = Int(1,3);
        Space();
        if(op == 1){
            int x = Int(1,nMax);
            num_query1++;
        }else{
            int a = Int(0,nMax-1); 
            Space();
            int b = Int(a+1,nMax);
            int ch = op == 2 ? 1 : -1;
            keys[{a,b}] += ch;
            if(keys[{a,b}] < 0) assert(false); //Can't delete non-existing key.
        }
        Endl();
    }

    if(Arg("fewUnlock",0)) assert(num_query1 <= 20);
    
    if(Arg("noDelDiffB",0)){
        assert(num_query1 + keys.size() == Q);
        set<int> all_Bs; 
        for(const auto &pr : keys){
            all_Bs.insert(pr.first.second);
        }
        assert(all_Bs.size() == keys.size());
    }
}
