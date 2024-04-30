#include <iostream>

using namespace std;

void solution() {
  int X, Y;

  cin >> Y >> X;
  for (int y = 0; y < Y; ++y) {
    for (int x = 0; x < X; ++x) {
      cout << ((y + x) % 2 ? '.' : '*');
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