#include <iostream>

using namespace std;

void solution() {
  int N, result, a;

  cin >> N;
  while (N != 0) {
    result = 0;
    for (int i = 1; i <= N; i++) {
      a = N-i+1;
      result += a*a;
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