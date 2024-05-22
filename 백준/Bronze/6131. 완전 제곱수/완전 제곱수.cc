#include <iostream>

using namespace std;

void solution() {
  long long N, A, B, count = 0;

  cin >> N;
  for (A = 1; A <= 500; A++) {
    for (B = 1; B <= A; B++) {
      count += (A * A == B * B + N);
    }
  }

  cout << count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}