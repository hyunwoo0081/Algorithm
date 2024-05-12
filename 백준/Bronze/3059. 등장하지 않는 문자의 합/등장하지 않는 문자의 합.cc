#include <iostream>

using namespace std;

void solution() {
  int T, sum;
  string s;
  int counts[26] = {0, };

  cin >> T;
  while (T--) {
    cin >> s;

    for (auto &a : counts)
      a = 0;

    for (auto c : s)
      counts[c - 'A']++;

    sum = 0;
    for (int i = 0; i < 26; i++) {
      if (counts[i] == 0)
        sum += i + 'A';
    }
    cout << sum << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}