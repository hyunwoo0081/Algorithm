#include <iostream>
#define SIZE 10000

using namespace std;

bool slot[SIZE] = {false};
void solution() {
    int N, Q, L, I, count = 0;

    cin >> N >> Q;
    while (Q--) {
        cin >> L >> I;
        for (int i = L-1; i < N; i += I)
            slot[i] = true;
    }

    for (int i = 0; i < N; i++)
        count += !slot[i];
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}