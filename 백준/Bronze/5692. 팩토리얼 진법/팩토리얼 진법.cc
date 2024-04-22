#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  int N, result, fact, i;

  cin >> N;
  while (N != 0) {
    result = 0;
    fact = 1;
    i = 1;

    while (N > 0) {
      fact *= i++;
      result += (N % 10) * fact;
      N /= 10;
    }

    cout << result << '\n';
    cin >> N;
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}