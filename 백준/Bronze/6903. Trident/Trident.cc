#include <iostream>

using namespace std;

void solution() {
  int t, s, h;

  cin >> t >> s >> h;
  while (t--) {
    cout << '*';
    for (int i = 0; i < s; i++)
      cout << ' ';
    cout << '*';
    for (int i = 0; i < s; i++)
      cout << ' ';
    cout << "*\n";
  }

  for (int i = 0; i < 2 * s + 3; i++) {
    cout << '*';
  }
  cout << '\n';

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < s + 1; j++)
      cout << ' ';
    cout << "*\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}