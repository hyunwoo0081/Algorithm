#include <iostream>

using namespace std;

void solution() {
  long long C, K, P, result = 0;

  cin >> C >> K >> P;

  while (C) {
    result += K*C + P*C*C;
    C--;
  }
  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}