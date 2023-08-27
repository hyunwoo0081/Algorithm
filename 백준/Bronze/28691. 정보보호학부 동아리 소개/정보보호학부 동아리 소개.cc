#include <iostream>

using namespace std;

void solution() {
    char c;

    cin >> c;
    switch (c) {
        case 'M':
            cout << "MatKor"; break;
        case 'W':
            cout << "WiCys"; break;
        case 'C':
            cout << "CyKor"; break;
        case 'A':
            cout << "AlKor"; break;
        case '$':
            cout << "$clear"; break;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}