#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int cntBoard; cin >> cntBoard;

  for (int i = 0; i < cntBoard; i++) {
    int cntPieces; cin >> cntPieces;
    vector<int> rows(8, 0);
    for (int j = 0; j < cntPieces; j++) {
      int x, y; cin >> x >> y;

      rows[y - 1]++;
    }

    int maxPieces = *max_element(rows.begin(), rows.end());
    cout << maxPieces << "\n";
  }

  return 0;
}