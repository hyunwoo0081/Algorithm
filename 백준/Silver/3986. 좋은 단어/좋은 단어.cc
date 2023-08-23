#include <iostream>
#define SIZE 1000000

using namespace std;

char stack[SIZE];
int stackSize = 0;

void solution() {
    int N, count = 0;
    string s;

    cin >> N;
    while (N--) {
        cin >> s;

        stackSize = 0;
        for (auto c : s) {
            if (stackSize == 0 || stack[stackSize-1] != c)
                stack[stackSize++] = c;
            else
                stackSize--;
        }

        count += stackSize == 0;
    }
    cout << count;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}