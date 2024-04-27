#include <iostream>

using namespace std;

void solution() {
  int T, px, py, pz, cx, cy, cz;

  cin >> T;
  while (T--) {
    cin >> px >> py >> pz >> cx >> cy >> cz;
    cout << abs(px - cx) + abs(py - cy) + pz + cz << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}