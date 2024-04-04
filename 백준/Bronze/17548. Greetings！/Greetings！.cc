#include <iostream>

using namespace std;

void solution() {
  string s;

  cin >> s;
  for (auto c : s) {
    if (c == 'e')
      cout << "ee";
    else
      cout << c;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}