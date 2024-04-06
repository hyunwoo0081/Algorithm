#include <iostream>

using namespace std;

void solution() {
  int T, N, half, cnt, result = 0;
  string s;
  cin >> T >> N;
  half = (N + 1) / 2;
  while (T--) {
    cnt = 0;
    cin >> s;
    for (auto c : s)
      cnt += c == 'O';
    result += cnt >= half;
  }

  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}