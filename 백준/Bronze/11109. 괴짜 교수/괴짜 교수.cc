#include <iostream>

using namespace std;

void solution() {
  long long T, d, n, s, p;

  cin >> T;
  while (T--) {
    cin >> d >> n >> s >> p;
    
    long long a = d + n * p;
    long long b = n * s;

    if (a > b) {
      cout << "do not parallelize\n";
    } else if (a < b) {
      cout << "parallelize\n";
    } else {
      cout << "does not matter\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}