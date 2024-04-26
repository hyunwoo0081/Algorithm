#include <iostream>

using namespace std;

void solution() {
  int N, W, H, l;

  cin >> N >> W >> H;
  while (N--) {
    cin >> l;

    cout << (l * l <= W * W + H * H ? "YES" : "NO") << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}