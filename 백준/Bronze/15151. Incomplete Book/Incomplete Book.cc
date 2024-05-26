#include <iostream>

using namespace std;

void solution() {
  long long K, D, sum, r, cnt = 0;

  cin >> K >> D;
  r = 1;
  for (sum = K; sum <= D; sum += r*K) {
    cnt++;
    r *= 2;
  }

  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}