#include <iostream>

using namespace std;

void solution() {
  long long X1, Y1, R1, X2, Y2, R2;
  long long distX, distY, dist;

  cin >> X1 >> Y1 >> R1;
  cin >> X2 >> Y2 >> R2;

  distX = X1 - X2;
  distY = Y1 - Y2;
  dist = distX * distX + distY * distY;

  cout << (dist < (R1+R2)*(R1+R2) ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}