#include <iostream>

using namespace std;

void solution() {
  int h1, m1, h2, m2;

  cin >> h1 >> m1 >> h2 >> m2;
  while (h1 || m1 || h2 || m2) {
    int start = h1 * 60 + m1;
    int end = h2 * 60 + m2;
    if (start > end) {
      end += 24 * 60;
    }
    cout << end - start << '\n';

    cin >> h1 >> m1 >> h2 >> m2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}