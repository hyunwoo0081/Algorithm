#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int dir[] = {4, 2, 3, 1};

void solution() {
    int arr[6][2];
    int K, max1 = 0, max2 = 0;

    cin >> K;
    for (int i = 0; i < 6; ++i) {
        cin >> arr[i][0] >> arr[i][1];

        if(i % 2) max1 = max(max1, arr[i][1]);
        else max2 = max(max2, arr[i][1]);
    }

    int index;
    for (index = 0; dir[index] != arr[0][0]; index++);

    int subArea = 0;
    for (int i = 1; i < 6; ++i) {
        int nextIndex = (index+1)%4;
        if (arr[i][0] != dir[nextIndex]) {
            subArea = arr[i-1][1] * arr[i][1];
            break;
        }
        index = nextIndex;
    }
    if (subArea == 0)
        subArea = arr[0][1] * arr[5][1];

    cout << (max1*max2 - subArea) * K;
}

int main() {
    fastIO();
    solution();

    return 0;
}