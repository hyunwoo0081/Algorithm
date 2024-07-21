#include <iostream>
#define ll long long

using namespace std;

ll arr[36] = {1, 1};

int main() {
    ll N, i, j;
    
    cin >> N;
    for (i = 2; i <= N; i++) {
        for (int j = 0; j < i; j++)
            arr[i] += arr[j] * arr[i-1-j];
    }
    
    cout << arr[N];

    return 0;
}