#include <iostream>

using namespace std;

void solution() {
    int arr[8], idx[8], tmp;
    bool selected[8] = {false};

    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
        idx[i] = i;
    }

    for (int i = 0; i < 7; i++)
        for (int j = 0; j < 7; j++)
            if (arr[idx[j]] < arr[idx[j+1]]) {
                tmp = idx[j];
                idx[j] = idx[j+1];
                idx[j+1] = tmp;
            }

    tmp = 0;
    for (int i = 0; i < 5; i++) {
        tmp += arr[idx[i]];
        selected[idx[i]] = true;
    }
    cout << tmp << '\n';
    for (int i = 0; i < 8; i++)
        if (selected[i])
            cout << i+1 << ' ';

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}