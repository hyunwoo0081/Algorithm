#include <iostream>

using namespace std;

void solution() {
  int L;
  double C, w, h, result = 0;

  cin >> C >> L;
  while (L--) {
    cin >> w >> h;
    result += w * h * C;
  }
  cout << fixed;
  cout.precision(7);
  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}