#include <iostream>

using namespace std;

void solution() {
  int sum, a;
  sum = 0;
  for (int i = 0; i < 4; i++) {
    cin >> a;
    sum += a;
  }
  cout << sum/60 << '\n' << sum%60;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}