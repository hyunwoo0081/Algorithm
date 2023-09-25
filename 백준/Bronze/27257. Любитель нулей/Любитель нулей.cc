#include <iostream>

using namespace std;

void solution() {
  int a, cnt = 0, isLast = false;

  cin >> a;
  while (a > 0) {
    if (a % 10 > 0)
			isLast = true;
		else if (isLast)
      cnt++;
    a /= 10;
  }
  cout << cnt;
}
 
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}