#include <iostream>

using namespace std;

void solution() {
  int arr[4], tmp;
  double f, maxN = 0, idx = 0;

  for (auto &a : arr)
    cin >> a;
  tmp = arr[3];
  arr[3] = arr[2];
  arr[2] = tmp;

  for (int i =  0; i < 4; i++) {
    f = arr[0] / (double)arr[3] + arr[1] / (double)arr[2];
    if (maxN < f) {
      maxN = f;
      idx = i;
    }

    tmp = arr[3];
    for (int j = 3; j > 0; j--)
      arr[j] = arr[j - 1];
    arr[0] = tmp;
  }

  cout << idx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}