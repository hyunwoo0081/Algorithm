#include <iostream>
#include <cmath>

using namespace std;

void solution() {
  int R;
  double S;

  while(cin >> R >> S) {
    cout << (long long)(sqrt((R * (S + .16)) / 0.067) + 0.5) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}