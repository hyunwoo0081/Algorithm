#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  int T, N, a, result = 0, p;

  cin >> T >> N;
  while (T--) {
    cin >> a;
    p = (int) pow(a, N);
    if (p > 0)
      result += p;
  }

  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}