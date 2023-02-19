#include <iostream>

using namespace std;

void solution() {
    int i = 0;
    string s;
    string ucpc = "UCPC";

    getline(cin, s);
    for (auto c: s) {
        if (i < 4 && ucpc[i] == c)
            i++;
    }
    
    if (i == 4)
        cout << "I love UCPC";
    else
        cout << "I hate UCPC";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}