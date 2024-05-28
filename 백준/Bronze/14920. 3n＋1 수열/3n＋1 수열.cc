#include <iostream>

using namespace std;

void solution() {
  int N, count = 1;

  cin >> N;
  while (N != 1) {
    if (N % 2 == 0) {
      N /= 2;
    } else {
      N = 3 * N + 1;
    }
    count++;
  }

  cout << count << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}