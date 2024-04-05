#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  long long a, b, c, d, cnt, result;

  cin >> a >> b >> c >> d;
  cnt = min(a, b) + min(c, d);

  for (result = 0; result * result <= cnt; result++);
  result--;

  cout << result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}