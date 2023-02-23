#include <iostream>
#define SIZE 50

using namespace std;

char map[SIZE][SIZE];

int getMaxCount(int N) {
    int maxNum = 1;

    for (int y = 0; y < N; y++) {
        int count = 1;
        for (int x = 1; x < N; x++) {
            if (map[y][x-1] == map[y][x])
                count++;
            else
                count = 1;
            maxNum = max(maxNum, count);
        }
    }

    for (int x = 0; x < N; x++) {
        int count = 1;
        for (int y = 1; y < N; y++) {
            if (map[y-1][x] == map[y][x])
                count++;
            else
                count = 1;
            maxNum = max(maxNum, count);
        }
    }

    return maxNum;
}

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

int bruteforceChanges(int N) {
    int maxNum = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 1; x < N; x++) {
            swap(map[y][x-1], map[y][x]);
            maxNum = max(maxNum, getMaxCount(N));
            swap(map[y][x-1], map[y][x]);
        }
    }

    for (int y = 1; y < N; y++) {
        for (int x = 0; x < N; x++) {
            swap(map[y-1][x], map[y][x]);
            maxNum = max(maxNum, getMaxCount(N));
            swap(map[y-1][x], map[y][x]);
        }
    }

    return maxNum;
}

void solution() {
    int N;
    string s;

    cin >> N;
    for (int y = 0; y < N; y++) {
        cin >> s;
        for (int x = 0; x < N; x++)
            map[y][x] = s[x];
    }

    cout << bruteforceChanges(N);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}