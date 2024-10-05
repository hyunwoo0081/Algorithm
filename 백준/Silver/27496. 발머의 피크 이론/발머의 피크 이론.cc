#include <iostream>
#define ll long long

using namespace std;

ll arr[10000] = {0};
int main() {
    long long N, L, a, sum = 0, maxCnt = 0;
    
    cin >> N >> L;
    for (int n = 0; n < N; n++) {
        cin >> a;
        sum += a;
        if (n >= L)
            sum -= arr[n % L];
        arr[n % L] = a;
        
        // 판단
        if (129 <= sum && sum <= 138)
            maxCnt++;
    }
    
    cout << maxCnt;

    return 0;
}