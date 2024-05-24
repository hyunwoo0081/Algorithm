#include <iostream>

using namespace std;

void solution() {
  long long T, A, E;

  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> A >> E;

    cout << "Data Set " << t << ":\n";
    if (A <= E) {
      cout << "no drought";
    } else {
      E *= 5;
      while (A > E) {
        cout << "mega ";
        E *= 5;
      }
      cout << "drought";
    }

    if (t < T) {
      cout << "\n\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}