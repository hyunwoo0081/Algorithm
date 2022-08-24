#include <iostream>

using namespace std;

void solution() {
    int N, v;
    int arr[100];

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cin >> v;

    int count = 0;
    for (int i = 0; i < N; i++)
        if (arr[i] == v) count++;
    cout << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}