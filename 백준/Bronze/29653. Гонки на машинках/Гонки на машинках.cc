#include <iostream>
#define SIZE 100
using namespace std;


int arr[SIZE][2];
void solution() {
    int N;
    double t, result = 987654321.;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i][0] >> arr[i][1];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][1] == arr[j][1]) continue;

            t = -(double)(arr[j][0] - arr[i][0]) / (arr[j][1] - arr[i][1]);
            if (t < 0) continue;

            result = min(result, t);
        }
    }

    cout.precision(6);
    cout << fixed;
    cout << result;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}