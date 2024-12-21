#include <iostream>

using namespace std;



int solution() {
    string s;
    int arr[3], result;
    int cnts[6] = {0,};

    cin >> s;
    for (auto &a : arr) {
        cin >> a;
        cnts[a-1]++;
    }

    result = 0;
    for (int i = 0; i < 6; i++) {
        if (s[i] == 'Y') {
            result = max(result ,(cnts[i] + 2) * (i+1));
        }
    }

    if (s[6] == 'Y') {
        for (int i = 0; i < 6; i++) {
            if (cnts[i] >= 2) {
                result = max(result, 4 * (i+1));
            }
        }
    }

    if (s[7] == 'Y') {
        int idx3 = -1;
        int idx2 = -1;
        int idx1 = -1;
        for (int i = 0; i < 6; i++) {
            if (cnts[i] == 3) {
                idx3 = i;
            } else if (cnts[i] == 2) {
                idx2 = i;
            } else if (cnts[i] == 1) {
                idx1 = i;
            }
        }

        if (idx3 != -1) {
            if (idx3 == 5) {
                result = max(result, 3*(6) + 10);
            } else {
                result = max(result, 3*(idx3+1) + 12);
            }
        } else if (idx2 != -1 && idx1 != -1) {
            if (idx2 > idx1) {
                result = max(result, (idx2+1) * 3 + (idx1+1) * 2);
            }
            else {
                result = max(result, (idx2+1) * 2 + (idx1+1) * 3);
            }
        }
    }

    bool isFlat = true;
    for (auto a : cnts) {
        isFlat &= a <= 1;
    }

    if (s[8] == 'Y' && isFlat && cnts[5] == 0) {
        result = max(result, 30);
    }

    if (s[9] == 'Y' && isFlat && cnts[0] == 0) {
        result = max(result, 30);
    }

    if (s[10] == 'Y') {
        int idx = -1;
        for (int i = 0; i < 6; i++) {
            if (cnts[i] == 3) {
                idx = i;
            }
        }

        if (idx >= 0) {
            result = max(result, 50);
        }
    }

    if (s[11] == 'Y') {
        int sum = 0;
        for (auto a: arr) {
            sum += a;
        }

        result = max(result, sum+12);
    }


    cout << result;

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}