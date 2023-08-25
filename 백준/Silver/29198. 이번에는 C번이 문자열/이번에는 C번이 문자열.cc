#include <iostream>
#include <algorithm>
#define SIZE 300

using namespace std;

string arr[SIZE];
int counts[28];

void solution() {
    int N, M, K;

    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sort(arr[i].begin(), arr[i].end());
    }
    sort(arr, arr+N);

    for (int i = 0; i < K; i++) {
        for (auto c : arr[i])
            counts[c-'A']++;
    }

    for (int i = 0; i < 28; i++)
        while (counts[i]--)
            cout << (char)('A' + i);

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}