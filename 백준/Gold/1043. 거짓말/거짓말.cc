#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool isKnown[50] = {false};
int unions[50];
int unionElement[50];

int findRoot(int x) {
    while (unions[x] >= 0)
        x = unions[x];
    return x;
}

void joinUnion(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);
    if (a == b) return;

    isKnown[a] = isKnown[b] = isKnown[a] || isKnown[b];

    if (-unions[a] > -unions[b]) {
        unions[b] = a;
    }
    else {
        unions[b] = min(unions[a]-1, unions[b]);
        unions[a] = b;
    }
}

void solution() {
    int N, M, K, x;

    cin >> N >> M >> K;
    //break
    if (K == 0) {
        cout << M;
        return;
    }

    //initialize
    for (int i = 0; i < N; ++i) {
        unions[i] = -1;
    }
    //inputs
    for (int i = 0; i < K; ++i) {
        cin >> x;
        isKnown[x-1] = true;
    }
    for (int i = 0; i < M; ++i) {
        cin >> K >> unionElement[i];
        K--, unionElement[i]--;

        for (int j = 0; j < K; ++j) {
            cin >> x;
            joinUnion(unionElement[i], x-1);
        }
    }

    //output
    int count = 0;
    for (int i = 0; i < M; ++i) {
        if (!isKnown[findRoot(unionElement[i])])
            count++;
    }
    cout << count;
}

int main() {
    fastIO();
    solution();

    return 0;
}