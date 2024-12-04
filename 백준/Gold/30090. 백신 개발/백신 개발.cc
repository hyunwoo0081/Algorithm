#include <iostream>
#define SIZE 91

using namespace std;

string names[9];
char str[SIZE];
int getOverlapIdx(string &s, unsigned int strLen) {
    int result = min((unsigned int)s.length(), strLen);
    bool isSame;

    for (; result > 0; result--) {
        isSame = true;
        for (int i = 0; i < result; i++)
            isSame &= str[strLen-result+i] == s[i];

        if (isSame)
            return result;
    }

    return result;
}

unsigned int minLength(int N, int visited, unsigned int strlen) {
    int overlap, f;
    int result = 987654321;
    if (visited == (1 << N)-1) {
        // str[strlen] = '\0';
        // cout << str << ' ' << strlen << '\n';
        return strlen;
    }

    for (int i = 0; i < N; i++) {
        if (visited & (1 << i)) continue;

        overlap = strlen == 0 ? 0 : getOverlapIdx(names[i], strlen);
        for (int j = overlap; j < names[i].length(); j++)
            str[strlen + j - overlap] = names[i][j];

        f = minLength(N, visited | (1 << i), strlen+names[i].length()-overlap);
        result = min(result, f);
    }

    return result;
}

void solution() {
    int N;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> names[i];

    cout << minLength(N, 0, 0);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}