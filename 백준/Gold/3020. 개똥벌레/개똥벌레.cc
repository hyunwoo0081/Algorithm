#include <iostream>
#define SIZE 500001

using namespace std;

int top[SIZE], bottom[SIZE];

void solution() {
  int N, H, a, count, minC, f;
  
  cin >> N >> H;
  for (int i = 0; i < N; i++) {
    cin >> a;
    if (i % 2) top[H-a+1]++;
    else bottom[a]++;
  }

  for (int i = H-1; i > 0; i--)
    bottom[i] += bottom[i+1];
  for (int i = 1; i <= H; i++)
    top[i] += top[i-1];

  minC = SIZE;
  for (int h = 1; h <= H; h++) {
    f = bottom[h] + top[h];
    if (f < minC) {
      minC = f;
      count = 1;
    }
    else if (f == minC)
      count++;
  }

  cout << minC << ' ' << count;
}
 
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}