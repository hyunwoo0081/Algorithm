#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int histograms[100000];

long long maxSquare(int start, int end) {
    if (start == end)
        return histograms[start];

    int mid = (start + end) / 2;
    long long maxS = max(maxSquare(start, mid), maxSquare(mid+1, end));

    int lo = mid, hi = mid+1;
    int minHeight = min(histograms[lo], histograms[hi]);
    maxS = max(maxS, (long long) minHeight*2);
    while (start < lo || hi < end) {
        if (lo > start && (hi == end || histograms[lo-1] > histograms[hi+1])) {
            minHeight = min(minHeight, histograms[--lo]);
        }
        else {
            minHeight = min(minHeight, histograms[++hi]);
        }
        maxS = max(maxS, (long long) (hi-lo+1) * minHeight);
    }

    return maxS;
}

void solution() {
    int N;

    cin >> N;
    while (N > 0) {
        for (int i = 0; i < N; ++i)
            cin >> histograms[i];
        cout << maxSquare(0, N-1) << '\n';

        cin >> N;
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}