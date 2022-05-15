#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long segTree[262144];

long long initSegTree(int start, int end, int index) {
    if (start == end) {
        cin >> segTree[index];
        return segTree[index];
    }

    int mid = (start + end) / 2;
    return segTree[index] = initSegTree(start, mid, 2*index+1)
            + initSegTree(mid+1, end, 2*index+2);
}

long long updateSegTree(int start, int end, int index, int numIndex, int num) {
    int mid = (start + end) / 2;
    if (start == end)
        return segTree[index] = num;

    if (numIndex <= mid)
        return segTree[index] = updateSegTree(start, mid, 2*index+1, numIndex, num) + segTree[2*index+2];
    return segTree[index] = segTree[2*index+1] + updateSegTree(mid+1, end, 2*index+2, numIndex, num);
}

long long getSum(int start, int end, int index, int front, int back) {
    long long sum = 0;
    int mid = (start + end) / 2;

    if (start == front && end == back)
        return segTree[index];

    if (front <= mid)
        sum += getSum(start, mid, 2*index+1, front, min(mid, back));
    if (mid+1 <= back)
        sum += getSum(mid+1, end, 2*index+2, max(front, mid+1), back);

    return sum;
}

void solution() {
    int N, Q, x, y, a, b;

    cin >> N >> Q;
    initSegTree(0, N-1, 0);

    while (Q--) {
        cin >> x >> y >> a >> b;
        cout << getSum(0, N-1, 0, min(x,y)-1, max(x,y)-1) << '\n';
        updateSegTree(0, N-1, 0, a-1, b);
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}