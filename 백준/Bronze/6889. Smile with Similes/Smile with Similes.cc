#include <iostream>

using namespace std;

void solution() {
  int n, m;
  string a[5], b[5];

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i] << " as " << b[j] << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}