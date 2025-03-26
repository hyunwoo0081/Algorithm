#include <iostream>

using namespace std;

void solution() {
    int T, G, C, E;

    cin >> T;
    while (T--) {
        cin >> G >> C >> E;
        cout << max(0, (E-C)*(2*G-1)) << '\n';
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}