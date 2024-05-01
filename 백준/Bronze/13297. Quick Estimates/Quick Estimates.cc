#include <iostream>

using namespace std;

void solution() {
  int N;
  string s;

  cin >> N;
  while (N--) {
    cin >> s;
    cout << s.size() << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}