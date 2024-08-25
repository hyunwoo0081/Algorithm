#include <iostream>
#define SIZE 100

using namespace std;

void solution() {
    int N, P, Q, b;
    int arr[SIZE], results[SIZE];
    bool isAvalable = true;

    cin >> N >> P >> Q;
    P -= Q;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b;
        arr[i] = b - arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (P > 0) {
            if (arr[i] >= 0 && arr[i] % P == 0) {
                results[i] = arr[i] / P;
            }
            else {
                isAvalable = false;
                break;
            }
        }
        else if (P < 0) {
            Q = -P;
            b = -arr[i];
            if (b >= 0 && b % Q == 0) {
                results[i] = b / Q;
            }
            else {
                isAvalable = false;
                break;
            }
        }
        else {
            if (arr[i] == 0) {
                results[i] = 0;
            }
            else {
                isAvalable = false;
                break;
            }
        }
    }

    if (isAvalable) {
        cout << "YES\n";
        for (int i = 0; i < N; i++) {
            cout << results[i] << " ";
        }
    }
    else {
        cout << "NO\n";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}