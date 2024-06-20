#include <iostream>

using namespace std;

void solution() {
  int N, X, prev = -1, sum = 0;

  cin >> N;
  while (N--) {
    cin >> X;
    if (prev + 1 != X) {
      sum += X;
    }
    prev = X;
  }

  cout << sum << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}