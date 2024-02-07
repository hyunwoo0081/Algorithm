#include <iostream>

using namespace std;

void solution() {
    int N, cnt = 0;
    string A, B;

    cin >> N >> A >> B;
    for (int i = 0; i < N; i++) {
        cnt += A[i] == B[i];
    }
    cout << cnt;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}