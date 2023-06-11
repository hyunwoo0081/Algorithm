#include <iostream>

using namespace std;

void solution() {
    char c;

    c = cin.get();
    while (!cin.eof()) {
        switch (c) {
            case 'i': cout << 'e'; break;
            case 'e': cout << 'i'; break;
            case 'I': cout << 'E'; break;
            case 'E': cout << 'I'; break;
            default: cout << c; break;
        }
        c = cin.get();
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}