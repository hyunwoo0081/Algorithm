#include <iostream>
#define SIZE 81

using namespace std;

void solution() {
    string s;
    char result[SIZE] = {'a'};
    char stack[SIZE];
    bool isUpper[SIZE];
    int stackSize = 0, si;

    getline(cin, s);
    while (s != "#") {
        stackSize = si = 0;
        for (int i = 0; i < s.length(); i++) {
            result[i] = s[i];
            isUpper[i] = false;
            if ('a' <= s[i] && s[i] <= 'z')
                stack[stackSize++] = s[i];
            else if ('A' <= s[i] && s[i] <= 'Z') {
                stack[stackSize++] = s[i] - 'A' + 'a';
                isUpper[i] = true;
            }
            else if (s[i] == ' ') {
                // pop
                while (stackSize > 0) {
                    while (!('a' <= s[si] && s[si] <= 'z') && !('A' <= s[si] && s[si] <= 'Z')) {
                        si++;
                    }

                    result[si] = stack[--stackSize] + (isUpper[si] ? 'A'-'a' : 0);
                    si++;
                }
            }
        }
        result[s.length()] = '\0';

        // pop
        while (stackSize > 0) {
            while (!('a' <= s[si] && s[si] <= 'z') && !('A' <= s[si] && s[si] <= 'Z')) {
                si++;
            }

            result[si] = stack[--stackSize] + (isUpper[si] ? 'A'-'a' : 0);
            si++;
        }

        cout << result << '\n';

        getline(cin, s);
    }

}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}