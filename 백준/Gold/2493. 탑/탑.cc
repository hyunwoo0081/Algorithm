#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 500000

using namespace std;

int stack[SIZE][2];
int stackSize = 0;

void solution() {
    int N, L;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> L;
        while (stackSize > 0 && stack[stackSize-1][0] <= L) {
            stackSize--;
        }
        cout << (stackSize > 0 ? stack[stackSize-1][1]+1 : 0) << ' ';
        stack[stackSize][0] = L;
        stack[stackSize][1] = i;
        stackSize++;
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}