#include <iostream>

using namespace std;

void solution() {
  int a, b;
  cin >> a >> b;
  cout << (a*(100-b)/100.f < 100);
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}