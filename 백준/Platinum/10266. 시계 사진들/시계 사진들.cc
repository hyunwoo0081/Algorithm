#include <iostream>
#include <algorithm>
#define MOD 360'000

using namespace std;

int ai[400'000];
int m[200'000];
int f[200'200];

void solution() {
  int n;
  
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ai[i];
  for (int i = 0; i < n; i++)
    cin >> m[i];
  sort(ai, ai+n);
  sort(m, m+n);
  
  for (int i = 0; i < n; i++)
    ai[n+i] = ai[i]+MOD;
  for (int i = 0; i < 2*n-1; i++)
    ai[i] = (ai[i+1] - ai[i]) % MOD;
  for (int i = 0; i < n-1; i++)
    m[i] = (m[i+1] - m[i]) % MOD;
  n--;

  int j = f[0] = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && m[i] != m[j])
      j = f[j-1]-1;
    j = max(j, 0);

    j += (m[i] == m[j]);
    f[i] = j;
  }

  j = 0;
  for (int i = 0; i < 2*n+1; i++) {
    while (j > 0 && ai[i] != m[j])
      j = f[j-1];

    j += (ai[i] == m[j]);
    if (j >= n) {
      cout << "possible";
      return;
    }
  }
  cout << "impossible";
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}