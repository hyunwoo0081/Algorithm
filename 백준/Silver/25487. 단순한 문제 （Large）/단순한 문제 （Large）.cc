#include <iostream>

using namespace std;

void solution() {
    int T, a, b, c;

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> a >> b >> c;
        cout << min(min(a, b), c) << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}