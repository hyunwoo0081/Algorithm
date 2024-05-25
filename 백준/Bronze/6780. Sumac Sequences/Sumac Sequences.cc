#include <iostream>

using namespace std;

void solution() {
  int A, B, C, cnt = 2;

  cin >> A >> B;
  while (A >= B) {
    C = A - B;
    A = B;
    B = C;

    cnt++;
  }

  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}