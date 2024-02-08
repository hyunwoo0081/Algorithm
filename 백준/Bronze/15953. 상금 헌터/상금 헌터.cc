#include <iostream>

using namespace std;

int kakao2017[][2] = {
        {1, 5000000},
        {2, 3000000},
        {3, 2000000},
        {4, 500000},
        {5, 300000},
        {6, 100000},
};

int kakao2018[][2] = {
        {1, 5120000},
        {2, 2560000},
        {4, 1280000},
        {8, 640000},
        {16, 320000},
};

int getMoney(int arr[][2], int arrSize, int rank) {
    int rankSum = 0;
    if (rank <= 0)
        return 0;

    for (int i = 0; i < arrSize; i++) {
        rankSum += arr[i][0];
        if (rank <= rankSum)
            return arr[i][1];
    }

    return 0;
}

void solution() {
    int T, a, b;

    cin >> T;
    while (T--) {
        cin >> a >> b;

        cout << getMoney(kakao2017, 6, a) + getMoney(kakao2018, 5, b) << '\n';
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}