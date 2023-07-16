#include <iostream>

using namespace std;

void solution() {
    string name;
    string FBI = "FBI";
    int matched;
    bool isExist = false;

    for (int i = 0; i < 5; i++) {
        cin >> name;

        matched = 0;
        for (auto c : name) {
            if (c == FBI[matched])
                matched++;
            else
                matched = 0;

            if (matched == 3) {
                isExist = true;
                cout << i + 1 << ' ';
                break;
            }
        }
    }

    if (!isExist)
        cout << "HE GOT AWAY!";
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}