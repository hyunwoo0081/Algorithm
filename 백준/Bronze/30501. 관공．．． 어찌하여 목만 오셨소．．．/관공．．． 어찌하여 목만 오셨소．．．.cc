#include <iostream>

using namespace std;

void solution() {
    int T;
    bool isS;
    string s;

    cin >> T;
    while (T--) {
      cin >> s;

      isS = false;
      for (auto c : s) {
        isS |= c == 'S';
      }

      if (isS)
        cout << s;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}