#include <iostream>

using namespace std;

void solution() {
    int T;
    string name;
    bool isAnj = false;

    cin >> T;
    while (T--) {
        cin >> name;
        if (name == "anj")
            isAnj = true;
    }
    cout << (isAnj ? "뭐야;" : "뭐야?");
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}