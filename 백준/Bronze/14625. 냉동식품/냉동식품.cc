#include <iostream>

using namespace std;

void solution() {
  int fromH, fromM, toH, toM, N, cnt = 0;
  cin >> fromH >> fromM >> toH >> toM >> N;

  while (fromH < toH || fromH == toH && fromM <= toM) {
    if (fromH % 10 == N || fromM % 10 == N || fromM / 10 == N || fromH / 10 == N)
      cnt++;
    fromM++;
    if (fromM == 60) {
      fromM = 0;
      fromH++;
    }
  }
  cout << cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}