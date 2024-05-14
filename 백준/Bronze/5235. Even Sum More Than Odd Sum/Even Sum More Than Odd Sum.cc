#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
  int T, N, a, even, odd;

  cin >> T;
  while (T--) {
    cin >> N;
    even = odd = 0;

    while (N--) {
      cin >> a;
      if (a % 2 == 0) {
        even += a;
      } else {
        odd += a;
      }
    }

    if (even > odd) {
      cout << "EVEN\n";
    } else if (even < odd) {
      cout << "ODD\n";
    } else {
      cout << "TIE\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}