#include <iostream>

using namespace std;

void solution() {
  long long N, tmp, cnt = 0;

  cin >> N;
  for (; N >= 3; N--) {
    tmp = N;
    while (tmp > 0) {
      cnt += (tmp % 10) % 3 == 0 && tmp % 10 > 0;
      tmp /= 10;
    }
  }

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}