#include <iostream>

using namespace std;

void solution() {
  int n, k, d, s;
  double ans;

  cin >> n >> k >> d >> s;
  ans = (n*d - k*s) / (double)(n-k);

  cout.precision(10);
  if (ans < 0 || ans > 100) {
    cout << "impossible" << endl;
  } else {
    cout << ans << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}