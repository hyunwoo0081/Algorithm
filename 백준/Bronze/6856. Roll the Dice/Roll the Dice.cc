#include <iostream>

using namespace std;

void solution() {
  int N, M, cnt = 0;

  cin >> N >> M;

  for (int n = 1; n <= N; n++)
    for (int m = 1; m <= M; m++)
      cnt += (n + m == 10);

  cout << "There " << (cnt == 1 ? "is " : "are ") << cnt << (cnt == 1 ? " way" : " ways") << " to get the sum 10.";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}