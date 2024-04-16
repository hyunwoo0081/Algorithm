#include <iostream>

using namespace std;

void solution() {
  int N, a, minI, minV;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (i == 0 || minV > a) {
      minI = i;
      minV = a;
    }
  }

  cout << minI;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}