#include <iostream>

using namespace std;

void solution() {
    int idx = 0, w, c;
    double maxN = 0, tmp;
    char arr[] = {'S', 'N', 'U'};

    for (int i = 0; i < 3; i++) {
        cin >> c >> w;
        tmp = w*10. / (c >= 500 ? c*10. - 500 : c*10.);
        if (maxN < tmp) {
            maxN = tmp;
            idx = i;
        }
    }

    cout << arr[idx];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}