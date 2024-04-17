#include <iostream>

using namespace std;

void solution() {
  int L, T;
  string name;

  L = T = 0;
  for (int i = 0; i < 9; ++i) {
    cin >> name;
    if (name[0] == 'L') L++;
    else T++;
  }

  cout << (L > T ? "Lion" : "Tiger");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}