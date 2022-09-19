#include <iostream>
#define SIZE 262144

using namespace std;

int segTree[SIZE];

int getSign(int x) {
    if (x == 0) return 0;
    return x > 0 ? 1 : -1;
}

int makeSegTree(int start, int end, int index) {
    if (start == end) {
        cin >> segTree[index];
        return segTree[index] = getSign(segTree[index]);
    }
    int mid = (start+end)/2;
    segTree[index] = makeSegTree(start, mid, 2*index+1);
    segTree[index] *= makeSegTree(mid+1, end, 2*index+2);

    return segTree[index];
}

int updateSegTree(int start, int end, int index, int target, int value) {
    if (start == end)
        return segTree[index] = getSign(value);

    int mid = (start+end)/2;
    if (target <= mid)
        segTree[index] = updateSegTree(start, mid, 2*index+1, target, value)
                        * segTree[2*index+2];
    else
        segTree[index] = updateSegTree(mid+1, end, 2*index+2, target, value)
                         * segTree[2*index+1];

    return segTree[index];
}

int getValueSegTree(int start, int end, int index, int targetStart, int targetEnd) {
    if (start == targetStart && end == targetEnd)
        return segTree[index];

    int result = 1;
    int mid = (start+end)/2;
    if (targetStart <= mid)
        result *= getValueSegTree(start, mid, 2*index+1, targetStart, min(targetEnd, mid));
    if (mid+1 <= targetEnd)
        result *= getValueSegTree(mid+1, end, 2*index+2, max(targetStart, mid+1), targetEnd);
    return result;
}

void printValue(int value) {
    if (value == 0)
        cout << '0';
    else if(value > 0)
        cout << '+';
    else
        cout << '-';
}

void solution() {
    int N, K, i, j;
    string c;

    while (cin >> N >> K) {
        makeSegTree(0, N-1, 0);

        while (K--) {
            cin >> c >> i >> j;
            if (c[0] == 'C')
                updateSegTree(0, N-1, 0, i-1, j);
            else
                printValue(getValueSegTree(0, N-1, 0, i-1, j-1));
        }
        cout << '\n';
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}