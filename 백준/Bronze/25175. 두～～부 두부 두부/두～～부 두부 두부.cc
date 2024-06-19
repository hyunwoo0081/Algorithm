#include <iostream>

using namespace std;

void solution() {
  int N, M, K;

  cin >> N >> M >> K;
  M += K - 3;
  while (M < 0)
    M += N;

  cout << (M-1 + N) % N + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}