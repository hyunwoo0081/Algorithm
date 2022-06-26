#include <iostream>

using namespace std;
typedef long long ll;

bool dp[1000001] = {false};

void solution() {
  ll minN, maxN;
  
  cin >> minN >> maxN;

  for (ll i = 2; i*i <= maxN; i++) {
    ll j = minN / (i*i);

    if (minN % (i*i)) j++;
    
    for (; j*i*i <= maxN; j++) {
      dp[j*i*i-minN] = true;
    }
  }

  ll count = 0;
  for (ll i = 0; i <= maxN-minN; i++) {
    count += !dp[i];
  }
  
  cout << count;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();
}