#include <iostream>

using namespace std;

void solution() {
  int score, sum = 0;
  bool isHacker = false;

  for (int i = 0; i < 9; i++) {
    cin >> score;
    sum += score;
    if ((i/2 + 1) * 100 < score)
      isHacker = true;
  }

  if (isHacker) {
    cout << "hacker";
    return;
  }
  cout << (sum >= 100 ? "draw" : "none");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}