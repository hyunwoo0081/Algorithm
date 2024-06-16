#include <iostream>

using namespace std;

void solution() {
  int n;
  string s;

  cin >> s;
  for (auto c : s) {
    n = c;
    while (n > 0) {
      for (int i = 0; i < n%10; i++) {
        cout << c;
      }
      n /= 10;
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