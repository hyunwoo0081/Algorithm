#include <iostream>
#define SIZE 100000

using namespace std;

int arr[SIZE];
int arrSize = 0;
void solution() {
  int N, K;

  cin >> N >> K;
  for (int i = 1; i<= N; i++) {
    if (i % 10 != K % 10 && i % 10 != (2*K) % 10)
      arr[arrSize++] = i;
  }

  cout << arrSize << '\n';
  for (int i = 0; i < arrSize; i++)
    cout << arr[i] << ' ';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}