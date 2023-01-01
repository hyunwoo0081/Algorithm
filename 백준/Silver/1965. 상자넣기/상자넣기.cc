#include <iostream>
#include <algorithm>
#define SIZE 1000

using namespace std;

int arr[SIZE];
int counts[SIZE] = {0};

int getLis(int N) {
    int maxN = 0;
    for (int i = 0; i < N; i++) {
        counts[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[j] < arr[i])
                counts[i] = max(counts[i], counts[j]+1);

        maxN = max(maxN, counts[i]);
    }
    return maxN;
}

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cout << getLis(N);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}