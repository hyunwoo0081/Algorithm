#include <iostream>

using namespace std;

void solution() {
  int N, a, cnt;

  cin >> N;
  while (N--) {
    cin >> a;
    cnt = 0;
    for (int i = 1; i <= a; i++) {
      cnt += a % i == 0;
    }

    cout << a << " " << cnt << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}