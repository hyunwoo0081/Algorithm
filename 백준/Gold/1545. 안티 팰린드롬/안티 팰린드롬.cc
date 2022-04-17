#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

char sorted[50];

bool isNonPel(int N) {
    for (int i = 0; i < N/2; ++i) {
        if (sorted[i] == sorted[N - i - 1])
            return false;
    }
    return true;
}

void solution() {
    int N = 0;
    string inputStr;

    cin >> inputStr;
    for (char c:inputStr) {
        sorted[N++] = c;
    }

    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < N-i-1; ++j) {
            if (sorted[j] > sorted[j+1]) {
                char tmp = sorted[j];
                sorted[j] = sorted[j+1];
                sorted[j+1] = tmp;
            }
        }
    }


    for (int i = 0; i < N/2; ++i) {
        if (sorted[N/2-1 - i] == sorted[(N+1)/2 + i]) {
            for (int j = (N+1)/2+i+ 1; j < N; ++j) {
                if (sorted[j] != sorted[N/2-1]) {
                    sorted[(N+1)/2 + i] = sorted[j];
                    sorted[j] = sorted[N/2-1];
                    break;
                }
            }
        }
    }

    if (isNonPel(N)) {
        for (int i = 0; i < N; ++i)
            cout << sorted[i];
    }
    else {
        cout << -1;
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}