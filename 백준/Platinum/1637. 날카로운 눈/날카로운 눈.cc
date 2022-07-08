#include <iostream>
#define SIZE 20000

using namespace std;
typedef long long ll;

int data[SIZE][3];

ll getCount(int x, int N) {
    ll count = 0;
    for (int n = 0; n < N; ++n) {
        if (data[n][0] > x) continue;
        count += (min(data[n][1], x) - data[n][0]) / data[n][2] + 1;
    }
    return count;
}

void printOddNum(int lo, int hi, int N) {
    int mid;

    while (lo < hi) {
        mid = lo + (hi - lo)/2;
        if (getCount(mid, N) % 2)
            hi = mid;
        else
            lo = mid+1;
    }

    ll count = getCount(lo, N);
    if (count%2)
        cout << lo << ' ' << count - getCount(lo-1, N);
    else
        cout << "NOTHING";
}

void solution() {
    int N, hi, lo;

    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> data[n][0] >> data[n][1] >> data[n][2];

        if (n == 0 || hi < data[n][1]) hi = data[n][1];
        if (n == 0 || lo > data[n][0]) lo = data[n][0];
    }

    printOddNum(lo, hi, N);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}