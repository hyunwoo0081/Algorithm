#include <iostream>

using namespace std;

void solution() {
  int A, B, C;

  cin >> A >> B >> C;
  if (A == B && B == C)
    cout << '*';
  else if (A == B)
    cout << 'C';
  else if (A == C)
    cout << 'B';
  else
    cout << 'A';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}