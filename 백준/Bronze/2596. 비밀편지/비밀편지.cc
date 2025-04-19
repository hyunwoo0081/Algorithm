#include <iostream>
#define NOT_SET (-1)
#define AMBIGUOUS (-2)

using namespace std;

string code[] = {
    "000000",
    "001111",
    "010011",
    "011100",
    "100110",
    "101001",
    "110101",
    "111010",
};

void solution() {
    int N, ambiguous = -1;
    string s, result;
    bool isAmbiguous = false;

    cin >> N >> s;
    for (int i = 0; i < N && !isAmbiguous; i++) {
        int selected = NOT_SET;
        for (int j = 0; j < 8; j++) {
            int cnt = 0;
            for (int k = 0; k < 6; k++) {
                cnt += (s[i*6 + k] != code[j][k]);
            }

            if (cnt < 2) {
                if (selected < 0) {
                    selected = j;
                } else if (selected != j) {
                    selected = AMBIGUOUS;
                    break;
                }
            }
        }

        if (selected >= 0)
            result += (char)('A' + selected);
        else {
            isAmbiguous = true;
            ambiguous = i+1;
        }

    }

    if (isAmbiguous)
        cout << ambiguous;
    else
        cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}