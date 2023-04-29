#include <iostream>
#define SIZE 1000

using namespace std;

int X[SIZE];
int L[SIZE];
char C[SIZE];

void solution() {
    int N, saveX, saveY;
    bool yes;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> X[i];
    for (int i = 0; i < N; i++)
        cin >> L[i];
    for (int i = 0; i < N; i++)
        cin >> C[i];

    yes = false;
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            if (abs(X[i]-X[j]) <= L[i]+L[j] && C[i] != C[j]) {
                yes = true;
                saveX = i+1;
                saveY = j+1;
                break;
            }

    if (yes)
        cout << "YES\n" << saveX << ' ' << saveY;
    else
        cout << "NO";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}