#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int N, L;
  cin >> N >> L;

  double s, c;
  cin >> s >> c;
  cout << setprecision(10) << fixed;
  double bike = (double)L / N;
  double run = L - bike;
  cout << bike / c + run / s << endl;
}
