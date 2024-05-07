#include <iostream>

using namespace std;

void solution() {
  long long a, b;

  cin >> a >> b;
  while (a || b) {
    cout << a/b << ' ' << a%b << " / " << b << '\n';

    cin >> a >> b;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}