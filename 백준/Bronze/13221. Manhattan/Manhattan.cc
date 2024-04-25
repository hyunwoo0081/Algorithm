#include <iostream>

using namespace std;

int abs(int a) {
  return a < 0 ? -a : a;
}

void solution() {
  int px, py, N, cx, cy, rx, ry, len, l;

  len = 987654321;
  cin >> px >> py >> N;
  while (N--) {
    cin >> cx >> cy;

    l = abs(px - cx) + abs(py - cy);
    if (len > l) {
      len = l;
      rx = cx;
      ry = cy;
    }
  }

  cout << rx << ' ' << ry;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}