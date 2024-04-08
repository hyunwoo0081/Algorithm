#include <iostream>

using namespace std;

void solution() {
  long long A, B, C;

  cin >> A >> B >> C;
  cout << (A+B == C ? "correct!" : "wrong!");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}