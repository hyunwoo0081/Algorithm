#include <iostream>
#define SIZE 201

using namespace std;


int arr[SIZE];
int value[SIZE];
void solution() {
    int N, S, T;

    cin >> N;
    while (N) {
        cin >> S >> T;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 0; i <= N; i++)
            value[i] = -987654321;

        arr[N] = 0;
        for (int t = 0; t < T; t++) {
            for (int i = N; i >= 0; i--) {
                for (int s = 1; s <= S; s++) {
                    if (i - s >= 0) {
                        if (value[i - s] != -987654321)
                            value[i] = max(value[i], value[i - s] + arr[i]);
                    }
                    else {
                        value[i] = max(value[i], arr[i]);
                    }
                }
            }
        }

        cout << value[N] << '\n';
        cin >> N;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}