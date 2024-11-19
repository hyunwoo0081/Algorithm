#include <iostream>
#define SIZE 5000

using namespace std;

int arr[SIZE];
int stack[SIZE];
int stackSize = 0;

int direction(int a) {
    if (a > 0)
        return 1;
    if (a < 0)
        return -1;
    return 0;
}

int abs(int a) {
    return a > 0 ? a : -a;
}

void solution() {
    int N, i, j;

    cin >> N;
    for (i = 0; i < N; i++)
        cin >> arr[i];

    int result = 1;
    for (int s = 0; s < N; s++) {
        i = s;
        while (i+1 < N && arr[i] < arr[i+1])
            i++;
        while (i+1 < N && arr[i] > arr[i+1])
            i++;

        result = max(result, i-s+1);
    }

    cout << result;

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}