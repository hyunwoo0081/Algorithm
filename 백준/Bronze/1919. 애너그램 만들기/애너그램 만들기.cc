#include <iostream>

using namespace std;

int arr[26], brr[26];

void solution() {
    int result = 0;
    string a, b;

    cin >> a >> b;

    for (auto c : a)
        arr[c-'a']++;
    for (auto c : b)
        brr[c-'a']++;

    for (int i = 0; i < 26; i++)
        result += abs(arr[i] - brr[i]);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}