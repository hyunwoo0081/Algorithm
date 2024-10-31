#include <iostream>

using namespace std;

int abs(int a) {
    return a > 0 ? a : -a;
}

int dist(int p1[2], int p2[2]) {
    return abs(p2[0] - p1[0]) + abs(p2[1] - p1[1]);
}

int arr[3][2];
void solution() {
    int N, i, j, k, d1, d2;
    long long result = 0, maxDist = -987654321;

    cin >> N;
    for (int n = 0; n < N; n++) {
        i = n%3;
        j = (n+3-1)%3;
        k = (n+3-2)%3;
        cin >> arr[i][0] >> arr[i][1];

        if (n >= 1) {
            result += dist(arr[i], arr[j]);
        }
        if (n >= 2) {
            d1 = dist(arr[k], arr[j]) + dist(arr[j], arr[i]);
            d2 = dist(arr[k], arr[i]);

            maxDist = max(maxDist, (long long) d1-d2);
        }
    }

    cout << result - maxDist;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}