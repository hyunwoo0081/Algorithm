#include <iostream>
#define DAY 4
#define COUNT 5

using namespace std;


int R[DAY][COUNT], M[DAY][COUNT], A[COUNT];
int getMax(int day, int K, int N, int sum) {
    int result = 0;
    if (day >= K)
        return sum;

    for (int r = 0; r < N; r++)
        for (int m = 0; m < N; m++) {
            if (A[r] <= 0 || A[m] <= 0 || r == m && A[r] <= 1)
                continue;

            A[r]--, A[m]--;
            result = max(result,
                getMax(day+1, K, N, sum+R[day][r]+M[day][m]));
            A[r]++, A[m]++;
        }

    return result;
}

void solution() {
    int N, K, n, k;

    cin >> N >> K;
    for (n = 0; n < N; n++)
        cin >> A[n];

    for (k = 0; k < K; k++)
        for (n = 0; n < N; n++)
            cin >> R[k][n];

    for (k = 0; k < K; k++)
        for (n = 0; n < N; n++)
            cin >> M[k][n];

    cout << getMax(0, K, N, 0);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}