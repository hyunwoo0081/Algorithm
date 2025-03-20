#include <iostream>
#define SIZE 200000

using namespace std;

int arr[SIZE];
int arrSize = 0;

void solution() {
    int N, M, K, o;

    cin >> N >> M >> K;
    for (int i = 1; arrSize < N && i <= M; i++) {
        o = i ^ K;
        if (0 < o && o < i) continue;
        arr[arrSize++] = i;
    }

    if (arrSize < N) {
        cout << -1 << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}