#include <iostream>

using namespace std;

int stacks[4][2] = {0};
int stackSize = 0;

void solution() {
    string s;
    bool isPositive = true;

    cin >> s;

    if (s == "0") {
        cout << "W";
        return;
    }

    // parsing
    int i = 0;
    if (s[0] == '-' || s[0] == '+') {
        isPositive = s[0] != '-';
        i++;
    }

    for (; i < s.length(); i++) {
        char c = s[i];
        if ('0' <= c && c <= '9') {
            stacks[stackSize][0] *= 10;
            stacks[stackSize][0] += c - '0';
        }
        else if (c == 'x') {
            stacks[stackSize][1]++;
        }
        else if (c == '+' || c == '-') {
            stacks[stackSize][0] = max(1 , stacks[stackSize][0]);
            if (!isPositive)
                stacks[stackSize][0] *= -1;

            isPositive = c == '+';
            stackSize++;
        }
    }
    stacks[stackSize][0] = max(1 , stacks[stackSize][0]);
    if (!isPositive)
        stacks[stackSize][0] *= -1;
    stackSize++;

    for (i = 0; i < stackSize; i++) {
        stacks[i][0] /= stacks[i][1]+1;
        stacks[i][1]++;
    }

    //output
    for (i = 0; i < stackSize; i++) {
        if (i != 0 || stacks[i][0] < 0) {
            cout << (stacks[i][0] < 0 ? '-' : '+');
        }

        stacks[i][0] = abs(stacks[i][0]);
        if (stacks[i][0] != 1 || stacks[i][1] == 0)
            cout << stacks[i][0];

        for (int j = 0; j < stacks[i][1]; j++) {
            cout << "x";
        }
    }
    cout << "+W";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}