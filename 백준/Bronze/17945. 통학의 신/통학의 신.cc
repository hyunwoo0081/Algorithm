#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  long long A, B, e;

  cin >> A >> B;
  if (A*A == B) {
    cout << -A;
  }
  else {
    e = sqrt(A*A-B);
    cout << -A - e << ' ' << -A + e;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}