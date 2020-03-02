#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+1;

struct Seg {
	int fr, to, in, ut;
	long long cost;
	Seg () {}
	Seg(int _fr, int _to) : fr(_fr), to(_to), in(0) {}
	Seg(int _in, int _ut, long long _cost) : in(_in), ut(_ut), cost(_cost) {}
} id(0,inf);

Seg concat(const Seg &a, const Seg &b){
	if(a.in && b.in) return Seg(a.in, b.ut, a.cost + b.cost + abs(b.in-a.ut));
	if(a.in) return Seg(a.in, max(min(a.ut, b.to), b.fr), a.cost + max(0, max(a.ut-b.to, b.fr-a.ut)));
	if(b.in) return Seg(max(min(b.in, a.to), a.fr), b.ut, b.cost + max(0, max(b.in-a.to, a.fr-b.in)));
	if(b.to <= a.fr) return Seg(a.fr, b.to, a.fr-b.to);
	if(a.to <= b.fr) return Seg(a.to, b.fr, b.fr-a.to);
	return Seg(max(a.fr,b.fr), min(a.to,b.to));
}

struct Node {
	int fr, to;
	Node *l, *r;
	Seg s;
	Node(int fr, int to, vector<Seg> &ls) : fr(fr), to(to){
		if(fr+1 == to) s = ls[fr];
		else {
			l = new Node(fr, (fr+to)/2, ls);
			r = new Node((fr+to)/2, to, ls);
			s = concat(l->s, r->s);
		}
	}
	Seg que(int lo, int hi){
		if(lo <= fr && to <= hi) return s;
		if(hi <= fr || to <= lo) return id;
		return concat(l->que(lo,hi), r->que(lo,hi));
	}
};

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);

	int n, q, _;
	cin >> n >> q >> _ >> _;
	
	vector<tuple<int,int,int>> ls(n);
	for(auto &p : ls){
		int t, x, y;
		cin >> t >> x >> y;
		p = {x,y,t};
	}
	sort(ls.begin(), ls.end());
	map<int, int> ren;
	for(int i = 0; i < n; ++i) ren[get<0>(ls[i])] = i;
	ren[inf] = n;
	vector<Seg> segs(n);
	for(int i = 0; i < n; ++i){
		auto [_,y,t] = ls[i];
		segs[i] = t==1 ? Seg(y, inf) : Seg(0, y);
	}
	Node root(0, n, segs);
	while(q--){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x2 < x1){
			swap(x1,x2);
			swap(y1,y2);
		}
		int i = ren.upper_bound(x1)->second, j = ren.upper_bound(x2)->second;
		cout << concat(Seg(y1,y1), concat(root.que(i,j), Seg(y2,y2))).cost + x2-x1 << endl;
	}
	_Exit(0);
}
