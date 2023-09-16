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

  int R, N;
  cin >> R >> N;
  string S;
  cin >> S;

  rep(r,0,S.size()) {
    rep(l,0,r) {
      if (S[r] != '.' && S[l] != '.' && abs(S[r] - S[l]) == r - l) {
        if (S[l] < S[r]) {
          rep(k,l+1,r) S[k] = S[l] + k - l;
        } else {
          rep(k,l+1,r) S[k] = S[r] + r - k;
        }
      }
    }
  }

  cout << S << endl;
}
