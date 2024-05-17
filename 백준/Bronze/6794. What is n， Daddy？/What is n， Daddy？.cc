#include <iostream>

using namespace std;

void solution() {
  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i <= 5; ++i) {
    for (int j = i; j <= 5; ++j) {
      if (i + j == n) {
        ++cnt;
      }
    }
  }

  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}