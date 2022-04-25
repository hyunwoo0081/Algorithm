#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void solution() {
    int N, K;
    int aCount, bCount;
    cin >> N >> K;

    aCount = N/2;
    bCount = (N+1)/2;
    if (K > aCount*bCount) {
        cout << -1;
    }
    else {
        int leftK = aCount*bCount - K;
        int backA = leftK / (bCount);
        int middle = leftK % (bCount);

        for (int i = 0; i < aCount-backA-1; ++i)
            cout << 'A';
        for (int i = 0; i < bCount; ++i) {
            if (i == middle && K != 0)
                cout << 'A';
            cout << 'B';
        }
        for (int i = 0; i < backA; ++i)
            cout << 'A';
    }
}


int main() {
    fastIO();
    solution();

    return 0;
}