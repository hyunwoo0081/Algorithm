#include <iostream>

using namespace std;

void solution() {
  int T, A, B, n;

  cin >> T;
  while (T--) {
    cin >> A >> B;
    n = A / B;
    cout << n * n << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}