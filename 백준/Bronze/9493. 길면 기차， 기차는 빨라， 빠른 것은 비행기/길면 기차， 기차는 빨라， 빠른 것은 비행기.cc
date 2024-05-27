#include <iostream>

using namespace std;

void print60(int sec) {
  if (sec < 10) {
    cout << "0" << sec;
  } else {
    cout << sec;
  }
}

void solution() {
  int M, A, B, sec;
  double speedA, speedB;

  cin >> M >> A >> B;
  while (M || A || B) {
    speedA = (double) M / A * 3600;
    speedB = (double) M / B * 3600;

    sec = (int) (speedA - speedB + 0.5);

    int hour = sec / 3600;
    int min = (sec / 60) % 60;
    sec %= 60;

    cout << hour << ":";
    print60(min);
    cout << ":";
    print60(sec);
    cout << '\n';

    cin >> M >> A >> B;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}