#include <iostream>

using namespace std;

void solution() {
  int T, N, prev, p;

  cin >> T;
  while (T--) {
    cin >> N >> prev;
    for (int i = 1; i < N; i++) {
      cin >> p;
      if (prev + 1 != p) {
        cout << i+1 << '\n';
        p = prev;
      }
      prev = p;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}