#include <iostream>
#define SIZE 10000

using namespace std;

char answer[SIZE];

void solution() {
  int N, count = 0;
  char sheet;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> answer[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> sheet;
    count += answer[i] == sheet;
  }

  cout << count;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}