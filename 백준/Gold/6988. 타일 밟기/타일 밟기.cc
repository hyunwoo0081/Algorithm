#include <iostream>
#define SIZE 3000

using namespace std;

int map[SIZE];
bool visited[SIZE][SIZE] = {false};

int findNum(int num, int start, int end) {
    int mid, E = end;
    while (start < end) {
        mid = (start + end) / 2;
        if (map[mid] < num) {
            start = mid + 1;
        }
        else if (map[mid] > num) {
            end = mid - 1;
        }
        else {
            return mid;
        }
    }

    if (0 <= end && map[end] == num)
        return end;
    if (start <= E && map[start] == num)
        return start;
    return -1;
}

long long getSum(int start, int end, int num, int d) {
    int index = findNum(num+d, start, end);
    if (index >= 0) {
        visited[start-1][index] = true;
        return num + getSum(index+1, end, num+d, d);
    }
    return num;
}

void solution() {
    int N, index;
    long long sum;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> map[i];
    }

    sum = 0;
    for (int s = 0; s < N - 2; ++s) {
        for (int n = s+1; n < N-1; ++n) {
            if (visited[s][n])
                continue;

            index = findNum(2*map[n]-map[s], n, N-1);
            if (index >= 0) {
                sum = max(sum, map[s] + map[n] + getSum(index+1, N-1, 2*map[n]-map[s], map[n]-map[s]));
                visited[s][n] = true;
                visited[n][index] = true;
            }
        }
    }

    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}