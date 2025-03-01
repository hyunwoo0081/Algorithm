#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solution() {
    string s1, s2;

    cin >> s1;
    while (s1 != "-1") {
        cin >> s2;
        int len1 = s1.length(), len2 = s2.length();
        int len = len1 + len2;
        int cnt, maxCnt = 0;

        for (int i = 1-len2; i < len1; i++) {
            cnt = 0;
            for (int j = 0; i+j < len1 && j < len2; j++) {
                if (i+j < 0) continue;
                cnt += s1[i+j] == s2[j];
            }
            maxCnt = max(maxCnt, cnt);
        }

        int g = gcd(len, 2*maxCnt);
        cout << "appx(" << s1 << "," << s2 << ") = ";

        if (maxCnt == 0)
            cout << "0\n";
        else if (2*maxCnt == len)
            cout << "1\n";
        else
            cout << 2 * maxCnt / g << "/" << len / g << '\n';

        cin >> s1;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}