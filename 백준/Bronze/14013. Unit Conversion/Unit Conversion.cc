#include <iostream>

using namespace std;

void solution() {
  double A, B, R;
  int N;
  char C;

  cin >> A >> B >> N;
  while (N--) {
    cin >> R >> C;

    if (C == 'A') {
      cout << R*B/A << '\n';
    } else if (C == 'B') {
      cout << R*A/B << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}