// usage: ./a.out input_file correct_output output_dir < contestants_output
#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define trav(a, x) for(auto& a : x)
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pii;

static string input_file, output_dir, answer_file;

void die(const string& msg) {
    cout << msg << endl;
    ofstream(output_dir + "/score.txt") << 0;
    exit(43);
}

void accept(long double score) {
    ofstream(output_dir + "/score.txt") << setprecision(2) << fixed << score;
    exit(42);
}

void judge_error(const string& msg) {
	cout << msg << endl;
	exit(1);
}

template <class F>
void assert_done(istream& is, F fail) {
    try {
        string dummy;
        is >> dummy;
		if (is) fail("extraneous data: " + dummy);
    } catch(...) {}
}

template <class F>
long double score(istream& is, vector<pii>& edges, int N, F fail) {
	int M = sz(edges);
	vector<bool> taken(4*N, 0);
	vector<pair<ll,ll> > position(4*N, {-1, -1});
	rep(i,0,N) {
		int a[4];
		if(!(is >> a[0] >> a[1] >> a[2] >> a[3])){
			fail("EOF");
		}
		
		rep(j,0,4){
			if(!(1 <= a[j] && a[j] <= 4*N))fail("Grid entry out of bounds");
			if(taken[a[j]-1])fail("Duplicate entry in grid");
			taken[a[j]-1] = 1;
			position[a[j]-1] = {i, j};
		}
	}
	assert_done(is, fail);
	long double ans = 0;
	trav(e, edges){
		int a = e.first-1;
		int b = e.second-1;
		assert(a >= 0 && a < 4*N && b >= 0 && b < 4*N);
		assert(position[a].first != -1 && position[b].first != -1);
		ll dx = position[a].first - position[b].first;
		ll dy = position[a].second - position[b].second;
		ll dist = dx*dx + dy*dy;
		ans += 1.0 / (long double)(dist);
	}
	return ans;
}

int main(int argc, char** argv) {
    if (argc < 4) exit(1);
    cin.sync_with_stdio(0);
    cin.tie(0);

    input_file = argv[1];
    answer_file = argv[2];
    output_dir = argv[3];

    ifstream fin(input_file);
    fin.exceptions(cin.failbit | cin.badbit | cin.eofbit);

    int T;
    fin >> T;

    int N, M, K;
    fin >> N >> M;

	vector<pii> edges;
	rep(j,0,M){
		int a,b;
		fin >> a >> b;
		edges.push_back({a, b});
	}

    assert_done(fin, die);
    fin.close();

	ifstream fans(answer_file);

    try {
		long double sc = score(cin, edges, N, die);
		long double bestsc = score(fans, edges, N, judge_error);
		long double ratio = sc / bestsc;
		if (T == 0) accept(0);
		else accept(10.0 * ratio * ratio);
    } catch(...) {
        die("IO failure");
    }
}
