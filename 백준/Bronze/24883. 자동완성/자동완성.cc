#include <iostream>

using namespace std;

void solution() {
    char c;

    cin >> c;
    if (c == 'N' || c == 'n')
        cout << "Naver D2";
    else
        cout << "Naver Whale";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}