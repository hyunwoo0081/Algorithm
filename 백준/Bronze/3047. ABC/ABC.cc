#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
  int arr[3];
  string s;

  for (int &i : arr) {
    cin >> i;
  }
  cin >> s;

  sort(arr, arr + 3);

  for (int i = 0; i < 3; i++) {
    cout << arr[s[i] - 'A'] << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}