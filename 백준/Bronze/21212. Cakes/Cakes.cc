#include <iostream>

using namespace std;

void solution() {
  int T, a, b, result = 987654321;

  cin >> T;
  while (T--) {
    cin >> a >> b;

    result = min(result, b/a);
  }
  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}