#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int counts[50] = {0};
int H[50];

void solution() {
    int N;
    double a;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    for (int center = 0; center < N; ++center) {
        for (int i = center+1; i < N; ++i) {
            if (i == center+1 || H[i] > a*(i-center)+H[center]) {
                a = (H[i]-H[center])/(double)(i-center);
                counts[center]++;
            }
        }

        for (int i = center-1; i >= 0; --i) {
            if (i == center-1 || H[i] > a*(i-center)+H[center]) {
                a = (H[i]-H[center])/(double)(i-center);
                counts[center]++;
            }
        }
    }

    int maxCount = 0;
    for (int i = 0; i < N; ++i) {
        maxCount = max(maxCount, counts[i]);
    }
    cout << maxCount;
}

int main() {
    fastIO();
    solution();

    return 0;
}