#include <iostream>

using namespace std;

void solution() {
  int A, B, K, X, res;
  cin >> A >> B >> K >> X;

  res = min(K+X, B) - max(K-X, A) + 1;

  if (res <= 0) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    cout << res << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}