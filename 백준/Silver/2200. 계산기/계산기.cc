#include <iostream>

using namespace std;

int getCount(int N) {
    int result = 0;
    while (N > 0) {
        result++;
        N /= 10;
    }

    return result;
}

void solution() {
    int N, a, result;

    cin >> N;
    result = 2*N-1;
    for (int i = 0; i <= N; i++) {
        cin >> a;
        if (i != 0 && a > 0) {
            result += getCount(a) + 1;
        }
    }
    result += 1;

    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}