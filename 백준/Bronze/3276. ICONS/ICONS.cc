#include <iostream>

using namespace std;

int abs(int a) {
  return a < 0 ? -a : a;
}

void solution() {
  int N, minI = 987654321, minJ = 0, j;

  cin >> N;
  for (int i = 1; i <= N; ++i) {
    j = N / i + (N % i != 0);

    if (abs(i - j) < abs(minI - minJ)) {
      minI = i;
      minJ = j;
    }
  }

  cout << minI << " " << minJ << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}