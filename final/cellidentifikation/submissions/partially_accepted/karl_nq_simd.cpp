#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <immintrin.h>
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
  rep(i, 0, (int)inp.size()) {
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
  rep(qi,0,Q) {
    string inp;
    cin >> inp;
    int val = toDecimal(inp);

    int index;
    int count = 0;
    int i = 0;
    __m256i mval = _mm256_set1_epi32(val), temp;
#define TEST { \
        temp = _mm256_cmpeq_epi32(_mm256_and_si256(mval, _mm256_loadu_si256((__m256i*)&nums[i])), mval); \
        if (_mm256_movemask_epi8(temp)) break; \
        i += 8; \
    }
    while (i + 16 <= N) {
        TEST
        TEST
    }
    for (; i < N; i++) {
        if ((val & nums[i]) == val) break;
    }
    if (i < N) {
        count = 1;
        index = i;
        i++;
        while (i + 16 <= N) {
            TEST
            TEST
        }
        for (; i < N; i++) {
            if ((val & nums[i]) == val) break;
        }
        if (i != N) count = 2;
    }

    if (count == 0)
      cout << "finns ej" << endl;
    else if (count == 1)
      cout << index + 1 << endl;
    else
      cout << "vet ej" << endl;
  }
}
