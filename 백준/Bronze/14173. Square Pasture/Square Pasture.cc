#include <iostream>

using namespace std;

void solution() {
  int x1, y1;
  int minX, minY, maxX, maxY, l;

  minX = minY = 987654321;
  maxX = maxY = -987654321;
  for (int i = 0; i < 4; i++) {
    cin >> x1 >> y1;
    minX = min(minX, x1);
    minY = min(minY, y1);
    maxX = max(maxX, x1);
    maxY = max(maxY, y1);
  }

  l = max(maxX - minX, maxY - minY);
  cout << l*l;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}