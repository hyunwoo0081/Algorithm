#include <iostream>

using namespace std;

void solution() {
  int N, cost = 0;

  while (cin >> N) {
    switch (N) {
      case 1: cost += 500; break;
      case 2: cost += 800; break;
      case 3: cost += 1000; break;
    }
  }

  cout << 5000 - cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}