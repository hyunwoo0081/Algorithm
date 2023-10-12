#include <iostream>

using namespace std;

void solution() {
    int N, result = 0;
    string s;
    bool isContain;

    cin >> N;
    while (N--) {
        cin >> s;
        isContain = false;

        for (int i = 0; i < s.length()-1; i++)
            isContain |= s[i] == '0' && s[i+1] == '1' || s[i] == 'O' && s[i+1] == 'I';

        result += isContain;
    }

    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}