#include <iostream>

using namespace std;

void solution() {
  int N, H, a, count = 0;

  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    cin >> a;
    count += a <= H;
  }

  cout << count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}