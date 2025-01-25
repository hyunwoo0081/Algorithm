#include <iostream>
#include <algorithm>
#define SIZE 10000

using namespace std;

int vs[SIZE][2];
bool board[2*SIZE] = {false};
int coord[2*SIZE];
int coordSize = 0;

int findIdx(const int a) {
    int low = 0, high = coordSize-1;

    while (low < high) {
        const int mid = (low + high) / 2;

        if (coord[mid] < a)
            low = mid + 1;
        else if (coord[mid] == a)
            return mid;
        else
            high = mid - 1;
    }
    return low;
}

void solution() {
    int N, i, j;

    cin >> N;
    for (i = 0; i < N; i++) {
        cin >> vs[i][0] >> vs[i][1];
        coord[coordSize++] = vs[i][0];
        coord[coordSize++] = vs[i][1];
    }

    sort(coord, coord+coordSize);

    // remove duplicated coords
    for (i = 0, j = 0; i < coordSize; i++) {
        if (i == 0 || coord[j-1] != coord[i])
            coord[j++] = coord[i];
    }
    coordSize = j;

    
    int result = 0;
    for (i = N-1; i >= 0; i--) {
        bool visible = false;
        int s = findIdx(vs[i][0]);
        int e = findIdx(vs[i][1]);

        for (; s <= e; s++) {
            visible |= !board[s];
            board[s] = true;
        }
        result += visible;
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