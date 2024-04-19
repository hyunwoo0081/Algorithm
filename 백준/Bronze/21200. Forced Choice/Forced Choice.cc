#include <iostream>

using namespace std;

void solution() {
  int N, P, T, T2, a;
  bool canRemove;

  cin >> N >> P >> T;
  while (T--) {
    cin >> T2;
    canRemove = true;
    while (T2--) {
      cin >> a;
      canRemove &= a != P;
    }

    cout << (canRemove ? "REMOVE\n" : "KEEP\n");
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}