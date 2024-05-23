#include <iostream>

using namespace std;

long long min(long long a, long long b) {
  return a < b ? a : b;
}

long long max(long long a, long long b) {
  return a > b ? a : b;
}

void solution() {
  long long A, B, C, count = 0;

  cin >> A >> B;

  while (B != A) {
    C = max(A, B) - min(A, B);
    B = min(A, B);
    A = C;

    count++;
  }

  cout << count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}