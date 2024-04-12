#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  int N, cnt = 0;

  cin >> N;
  for (int i = 0; i < 30; i++) {
    if ((N & (1 << i)) != 0) {
      cout << i << ' ';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}