#include <iostream>

using namespace std;

void solution() {
  int T, N, M;

  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N >> M;
    cout << "Case " << t << ": " << M - (N-1) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}