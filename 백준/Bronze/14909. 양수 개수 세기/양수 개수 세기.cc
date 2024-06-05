#include <iostream>

using namespace std;

void solution() {
  int a, count = 0;

  while (cin >> a) {
    count += a > 0;
  }

  cout << count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}