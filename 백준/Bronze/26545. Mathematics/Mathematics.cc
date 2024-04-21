#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  int N, a, sum = 0;

  cin >> N;
  while (N--) {
    cin >> a;
    sum += a;
  }

  cout << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}