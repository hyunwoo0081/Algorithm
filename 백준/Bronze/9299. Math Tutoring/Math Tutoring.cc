#include <iostream>

using namespace std;

void solution() {
  int T, N, a;

  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    cout << "Case " << t << ": " << N - 1;

    for (int n = N; n >= 0; n--) {
      cin >> a;
      if (n > 0)
        cout << ' ' << n * a;
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