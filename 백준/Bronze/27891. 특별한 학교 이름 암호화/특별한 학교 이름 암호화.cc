#include <iostream>

using namespace std;

char decrease(char a) {
    return a == 'a' ? 'z' : (char) (a - 1);
}

void solution() {
    string s;
    bool printed = false;

    cin >> s;
    for (int i = 0; !printed && i < 27; i++) {
        if (s == "northlondo")
            printed = true, cout << "NLCS";
        else if (s == "branksomeh")
            printed = true, cout << "BHA";
        else if (s == "koreainter")
            printed = true, cout << "KIS";
        else if (s == "stjohnsbur")
            printed = true, cout << "SJA";

        for (auto &c : s)
            c = decrease(c);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}