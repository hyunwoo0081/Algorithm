#include <iostream>

using namespace std;

void solution() {
  int N, M;

  cin >> N >> M;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (x != 0)
        cout << ' ';
      cout << (y * M + x + 1);
    }
    cout << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}