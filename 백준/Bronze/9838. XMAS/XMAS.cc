#include <iostream>

using namespace std;

int arr[20001] = {0};

void solution() {
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr[a-1] = i + 1;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}