#include <iostream>

using namespace std;

void solution() {
  int N, a, cnt = 0;

  cin >> N;
  while (N > 0) {
    cnt = 0;
    for (int i = 0; i < N; i++) {
      cin >> a;
      cnt += a;
    }
    cout << "Mary won " << N-cnt << " times and John won " << cnt << " times\n";
    cin >> N;
  }

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}