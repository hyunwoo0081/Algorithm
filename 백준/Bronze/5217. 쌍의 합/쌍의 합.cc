#include <iostream>

using namespace std;

void solution() {
  int T, N;
  bool printed;

  cin >> T;
  while (T--) {
    cin >> N;
    cout << "Pairs for " << N << ":";

    printed = false;
    for (int i = 1; i <= N; i++) {
      for (int j = i+1; j <= N; j++) {
        if (i + j == N) {
          if (!printed) {
            printed = true;
          } else {
            cout << ",";
          }

          cout << " " << i << " " << j;
        }
      }
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