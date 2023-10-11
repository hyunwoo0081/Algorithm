#include <iostream>
#include <algorithm>

using namespace std;

void solution() {
    string s, result, tmpStr;
    bool isSaved = false;
    int len;

    cin >> s;
    len = s.length();
    for (int i = 0; i < len-2; i++) {
        for (int j = i+1; j < len-1; j++) {
            tmpStr = s;
            reverse(tmpStr.begin(), tmpStr.begin() + i+1);
            reverse(tmpStr.begin() + i + 1, tmpStr.begin() + j+1);
            reverse(tmpStr.begin() + j + 1, tmpStr.end());

            if (!isSaved || result > tmpStr) {
                isSaved = true;
                result = tmpStr;
            }
        }
    }

    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}