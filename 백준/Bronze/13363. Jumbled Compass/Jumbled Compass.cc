#include <iostream>

using namespace std;

void solution() {
  int A, B;

  cin >> A >> B;
  cout << (B - A + 360 + 180 - 1) % 360 - 180 + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}