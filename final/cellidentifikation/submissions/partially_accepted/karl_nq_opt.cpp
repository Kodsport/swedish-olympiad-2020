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
  rep(i, 0, inp.size()) {
    int digit = inp[i] - '0';
    ret += digit * (1 << i);
  }
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;

  vi nums(N);
  rep(i, 0, N) {
    string inp;
    cin >> inp;
    nums[i] = toDecimal(inp);
  }

  int Q;
  cin >> Q;
  rep(i, 0, Q) {
    string inp;
    cin >> inp;
    int val = toDecimal(inp);

    int index;
    int count = 0;
    rep(i, 0, N) {
      if ((val & nums[i]) == val) {
        index = i;
        count++;
        if (count > 1) break;
      }
    }

    if (count == 0)
      cout << "finns ej" << endl;
    else if (count == 1)
      cout << index + 1 << endl;
    else
      cout << "vet ej" << endl;
  }
}
