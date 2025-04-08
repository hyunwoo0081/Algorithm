#include <iostream>
#define SIZE 29

using namespace std;

char mirrors[SIZE][2] = {
    {'A', 'A'},
    {'E', '3'},
    {'H', 'H'},
    {'I', 'I'},
    {'M', 'M'},
    {'O', 'O'},
    {'S', '2'},
    {'T', 'T'},
    {'U', 'U'},
    {'V', 'V'},
    {'W', 'W'},
    {'X', 'X'},
    {'Y', 'Y'},
    {'Z', '5'},
    {'b', 'd'},
    {'i', 'i'},
    {'l', 'l'},
    {'m', 'm'},
    {'n', 'n'},
    {'o', 'o'},
    {'p', 'q'},
    {'r', '7'},
    {'u', 'u'},
    {'v', 'v'},
    {'w', 'w'},
    {'x', 'x'},
    {'0', '0'},
    {'1', '1'},
    {'8', '8'},
};

char upper(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

char lower(char c) {
    if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

int findIdx(char c, int x) {
    for (int i = 0; i < SIZE; i++) {
        if (mirrors[i][x] == c)
            return i;
    }
    return -1;
}

void solution() {
    int left, right;
    string s;

    cin >> s;
    left = 0;
    right = s.size() - 1;
    while (left < right) {
        bool isMirror = false;
        for (int i = 0; i < 4; i++) {
            char first = i/2 ? upper(s[left]) : lower(s[left]);
            char second = i%2 ? upper(s[right]) : lower(s[right]);

            int idx0 = findIdx(first, 0);
            int idx1 = findIdx(first, 1);
            if (idx0 != -1 && mirrors[idx0][1] == second || idx1 != -1 && mirrors[idx1][0] == second) {
                isMirror = true;
                s[left] = first;
                s[right] = second;
                break;
            }
        }

        if (isMirror) {
            left++, right--;
            continue;
        }
        break;
    }

    if (left == right) {
        char low = lower(s[left]);
        char up = upper(s[left]);

        int idx0 = findIdx(low, 0);
        int idx1 = findIdx(up, 0);
        if (idx0 != -1 && mirrors[idx0][1] == low) {
            s[left] = low;
            left++, right--;
        }
        else if (idx1 != -1 && mirrors[idx1][1] == up) {
            s[left] = up;
            left++, right--;
        }
    }

    if (left > right) {
        cout << s;
    } else {
        cout << -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}