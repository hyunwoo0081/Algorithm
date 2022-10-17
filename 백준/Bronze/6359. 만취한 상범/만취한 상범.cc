#include <iostream>

using namespace std;

bool isOpen[101] = {false};

void solution() {
    int T, N;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 1; i <= N; i++)
            isOpen[i] = false;

        for (int i = 1; i <= N; i++)
            for (int j = 1; i*j <= N; j++)
                isOpen[i*j] = !isOpen[i*j];

        int count = 0;
        for (int i = 1; i <= N; i++)
            count += isOpen[i];

        cout << count << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
