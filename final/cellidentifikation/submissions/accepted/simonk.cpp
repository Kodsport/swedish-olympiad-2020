#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int toDecimal(const string& inp) {
  int ret = 0;
  rep(i, 0, sz(inp)) {
    int digit = inp[i] - '0';
    ret += digit * (1 << i);
  }
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;

  vi mins(1 << K, N), maxs(1 << K, -1);
  rep(i, 0, N) {
    string inp;
    cin >> inp;
    int val = toDecimal(inp);
    maxs[val] = max(maxs[val], i);
    mins[val] = min(mins[val], i);
  }

  for (int b = (1 << K) - 1; b >= 0; b--) {
    int b2 = b;
    do {
      int b3 = b2 - 1;
      b2 &= b3;
      int b4 = b2 | (b & b3);
      mins[b4] = min(mins[b4], mins[b]);
      maxs[b4] = max(maxs[b4], maxs[b]);
    } while (b2);
  }

  int Q;
  cin >> Q;
  rep(i, 0, Q) {
    string inp;
    cin >> inp;
    int val = toDecimal(inp);
    if (mins[val] > maxs[val])
      cout << "finns ej\n";
    else if (mins[val] == maxs[val])
      cout << mins[val] + 1 << "\n";
    else
      cout << "vet ej\n";
  }
}
