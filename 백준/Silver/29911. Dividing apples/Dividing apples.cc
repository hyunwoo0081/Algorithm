#include <iostream>
#define ll long long
#define SIZE 1'000'000

using namespace std;

ll arr[SIZE];

void solution() {
    ll N, minI = 0;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (i > 0) arr[i] += arr[i-1];
    }

    for (int i = 0; i < N; i++) {
        if (abs(arr[N-1]-2*arr[minI]) > abs(arr[N-1]-2*arr[i]))
            minI = i;
    }

    cout << minI+1;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}