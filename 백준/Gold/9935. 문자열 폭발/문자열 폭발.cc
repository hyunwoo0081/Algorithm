#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define SIZE 1000000

using namespace std;

char stack[SIZE];
int stackSize = 0;

bool isSame(string &E) {
    if (stackSize < E.size())
        return false;

    for (int i = 0; i < E.size(); ++i) {
        if (stack[stackSize-E.size()+i] != E[i])
            return false;
    }
    return true;
}

void solution() {
    string S, E;

    cin >> S >> E;
    for (int i = 0; i < S.size(); ++i) {
        stack[stackSize++] = S[i];

        if (isSame(E))
            stackSize -= E.size();
    }

    if (stackSize == 0) {
        cout << "FRULA";
    }
    else {
        for (int i = 0; i < stackSize; ++i) {
            cout << stack[i];
        }
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}