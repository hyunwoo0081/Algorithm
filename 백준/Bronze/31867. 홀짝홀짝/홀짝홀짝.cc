#include <iostream>

using namespace std;

bool checks[26] = {false};

void solution() {
    int n;
    string s;

    cin >> n >> s;

    int odd = 0;
    for (auto c : s) {
        odd += (c-'0') % 2;
    }
    int even = n - odd;

    if (odd == even) {
        cout << "-1\n";
    }
    else if (odd > even) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}