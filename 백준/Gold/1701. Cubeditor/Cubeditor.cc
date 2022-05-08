#include <iostream>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int failure[5000];

int kmpFunction(string &s, int start) {
    int i, j;
    int maxCount = 0;

    for (i = 0; i < s.size() - start; ++i)
        failure[i] = 0;

    j = 0;
    for (i = 1; i < s.size()-start; ++i) {
        while(j > 0 && s[start+i] != s[start+j])
            j = failure[j-1];

        if (s[start+i] == s[start+j])
            failure[i] = ++j;

        maxCount = max(maxCount, failure[i]);
    }

    return maxCount;
}

void solution() {
    int maxCount = 0;
    string s;

    cin >> s;
    for (int k = 0; k < s.size(); ++k) {
        maxCount = max(maxCount, kmpFunction(s, k));
    }

    cout << maxCount;
}

int main() {
    fastIO();
    solution();

    return 0;
}