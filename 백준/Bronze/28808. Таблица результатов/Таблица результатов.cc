#include <iostream>
#define SIZE 101

using namespace std;

void solution() {
  int N, M, count = 0;
  string s;

  cin >> N >> M;
  while (N--) {
    cin >> s;
    for (auto c : s) {
      if (c == '+') {
        count++;
        break;
      }
    }
  }

  cout << count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}