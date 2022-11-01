#include <iostream>

using namespace std;

bool isGoodSeq(string &s) {
    int i, j;
    bool isSame;

    for (int k = s.length()/2; k > 0; k--) {
        i = s.length() - 2*k;
        j = s.length() - k;

        isSame = true;
        while (j < s.length() && isSame)
            if (s[i++] != s[j++])
                isSame = false;

        if (isSame)
            return false;
    }
    return true;
}

bool makeGoodSeq(string &s, int length) {
    if (!isGoodSeq(s))
        return false;
    if (length <= 0)
        return true;

    for (char c = '1'; c <= '3'; c++) {
        s.push_back(c);
        if (makeGoodSeq(s, length-1))
            return true;
        s.pop_back();
    }
    return false;
}

void solution() {
    int N;
    string result;

    cin >> N;
    makeGoodSeq(result, N);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
