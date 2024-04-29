#include <iostream>

using namespace std;

void solution() {
  int N;

  cin >> N;
  while (N != 1) {
    if (N % 2 == 0) {
      cout << N << " ";
      N /= 2;
    } else {
      cout << N << " ";
      N = N * 3 + 1;
    }
  }
  cout << N;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}