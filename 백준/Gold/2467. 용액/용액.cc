#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> sols;

void solution() {
  int n, a, b;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    sols.push_back(a);
  }
  sort(sols.begin(), sols.end());

  int i, j, minAbs = (1<<31)-1;
  i = 0, j = sols.size()-1;
  while (i < j) {
    if (abs(sols[i]+sols[j]) < minAbs) {
      a = sols[i], b = sols[j];
      minAbs = abs(a + b);
    }
    if (sols[i]+sols[j] < 0)
      i++;
    else
      j--;
  }
  cout << a << ' ' << b;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}