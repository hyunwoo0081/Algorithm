#include <iostream>
#define SIZE 48

using namespace std;

int origin[SIZE];
int p[SIZE];
int s[SIZE];
int sim[2][SIZE];

bool isSame(int arr[], int brr[], int N) {
    for (int i = 0; i < N; i++) {
        if (arr[i] != brr[i]) {
            return false;
        }
    }
    return true;
}

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
        sim[0][i] = p[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < N; i++) {
        origin[i] = i % 3;
        p[i] = sim[0][s[i]];
    }

    int result = 0;
    while (!isSame(sim[result%2], p, N) && !isSame(origin, sim[result%2], N)) {
        for (int i = 0; i < N; i++) {
            sim[(result+1)%2][s[i]] = sim[result%2][i];
        }
        result++;
    }

    if (isSame(origin, sim[result%2], N))
        cout << result;
    else
        cout << -1;
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}