#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  int N;
  double b, p;

  cin >> N;
  while (N--) {
    cin >> b >> p;

    double BPM = 60 * b / p;
    double minABPM = BPM - 60 / p;
    double maxABPM = BPM + 60 / p;

    cout << fixed;
    cout.precision(4);
    cout << minABPM << " " << BPM << " " << maxABPM << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}