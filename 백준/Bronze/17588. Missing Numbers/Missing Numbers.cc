#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  int N, a, cnt = 1;
  bool isGood = true;

  cin >> N;
  while (N--) {
    cin >> a;
    for (; cnt < a; cnt++) {
      isGood = false;
      cout << cnt << '\n';
    }
    cnt++;
  }

  if (isGood)
    cout << "good job";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}