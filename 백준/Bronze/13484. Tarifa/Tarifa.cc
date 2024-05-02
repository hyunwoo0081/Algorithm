#include <iostream>

using namespace std;

void solution() {
  int X, N, p, sum = 0;

  cin >> X >> N;
  while (N--) {
    cin >> p;
    sum += X - p;
  }
  cout << sum + X << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}