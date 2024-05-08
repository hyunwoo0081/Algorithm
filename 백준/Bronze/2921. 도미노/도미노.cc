#include <iostream>

using namespace std;

void solution() {
  long long N, sum = 0, i = 0, j = 0;

  cin >> N;
  cout << N * (N+1) * (N+2) / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}