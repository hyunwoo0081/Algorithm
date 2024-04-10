#include <iostream>

using namespace std;

void solution() {
  long long N;
  int arr[] = {2, 0, 1, 0};

  cin >> N;
  cout << arr[N%4];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}