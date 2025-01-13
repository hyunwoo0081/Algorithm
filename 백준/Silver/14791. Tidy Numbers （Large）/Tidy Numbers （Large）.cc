#include <iostream>

using namespace std;

long long stacks[20];
int stackSize = 0;
void solution() {
    long long T, N;

    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N;

        stackSize = 0;
        while (N > 0) {
            if (stackSize == 0 || N % 10 <= stacks[stackSize-1])
                stacks[stackSize++] = N % 10;
            else {
                for (int i = 0; i < stackSize; i++)
                    stacks[i] = 9;
                stacks[stackSize++] = --N % 10;
            }
            N /= 10;
        }

        N = 0;
        while (stackSize > 0) {
            N = N * 10 + stacks[--stackSize];
        }

        cout << "Case #" << t << ": ";
        cout << N << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}