#include <iostream>

using namespace std;

void solution() {
  long long T, a, b;
  double maxN, minN, sum, n;

  sum = 0;
  maxN = -1;
  minN = -1;
  cin >> T;
  while (T--) {
    cin >> a >> b;

    n =  a / (double) b;
    sum += n;
    if (maxN == -1 || n > maxN) {
      maxN = n;
    }
    if (minN == -1 || n < minN) {
      minN = n;
    }
  }

  cout.precision(11);
  cout << minN << " " << maxN << " " << sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}