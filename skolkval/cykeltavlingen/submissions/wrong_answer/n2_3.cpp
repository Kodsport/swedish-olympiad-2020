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

  double s1, c1, s2, c2;
  cin >> s1 >> c1 >> s2 >> c2;
  
  double res = max(L / s1, L / s2);
  if (s1 >= c1) res = min(res, max(L / s1, L / c2));
  else if (s2 >= c2) res = min(res, max(L / c1, L / s2));
  // s1 <= c1 <= s2 <= c2
  else if (false && c1 <= s2) res = L / c1;
  // s2 <= c2 <= s1 <= c1
  else if (c2 <= s1) res = L / c2;

  else {
    double S = c1 * s2 * L * (s1 - c2) / (c1 * s1 * (s2 - c2) - c1 * s2 * c2 + s1 * s2 * c2);
    res = min(res, S / c1 + (L - S) / s1);
    swap(s1, s2);
    swap(c1, c2);
    S = c1 * s2 * L * (s1 - c2) / (c1 * s1 * (s2 - c2) - c1 * s2 * c2 + s1 * s2 * c2);
    res = min(res, S / c1 + (L - S) / s1);
  }
  cout << setprecision(3) << fixed << res << endl;
}
