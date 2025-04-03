#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<string, int>> v;

void addWord(string &word, int count) {
    auto ptr = find_if(v.begin(), v.end(), [&](pair<string, int> p) {
                        return p.first == word;
                    });

    if (ptr >= v.end()) {
        v.emplace_back(word, count);
        return;
    }

    ptr->second += count;
}

void solution() {
    int T = 0;
    string s;

    getline(cin, s);
    while (s != "#") {
        bool isRightSide = false;
        int mult = 0;
        int count = 0;
        string word = "";
        T++;

        v.clear();
        for (auto c: s) {
            if (c == ' ' || c == '+' || c == '=') {
                if (!word.empty()) {
                    addWord(word, (isRightSide ? 1:-1)*max(1, mult)*max(1, count));
                    word.clear();
                    mult = count = 0;
                }

                if (c == '=')
                    isRightSide = true;
                continue;
            }

            if ('0' <= c && c <= '9') {
                if (word.empty())
                    mult = 10*mult + (c - '0');
                else
                    count = 10*count + (c - '0');
                continue;
            }

            if ('A' <= c && c <= 'Z') {
                if (!word.empty()) {
                    addWord(word, (isRightSide ? 1:-1)*max(1, mult)*max(1, count));
                    word.clear();
                    count = 0;
                }

                word += c;
                continue;
            }

            if ('a' <= c && c <= 'z') {
                word += c;
                continue;
            }

            // 소문자 -> 무조건 문자에 더함.
            // 대문자는 -> 새로운 원소 시작점
            // 숫자 -> 1. multi or 2. count | 구분 방법은 word 가 비어 있다면 multi 아니라면 count
            // 공백, + -> 무시 또는 word를 판단하는 수단 (고민중)
            // = -> word를 판단하는 수단 (고민중) + isRightSide = true
            // 문자열이 모두 종료 되면 word 추가;
        }

        // 마지막 단어 추가
        if (!word.empty()) {
            addWord(word, (isRightSide ? 1:-1)*max(1, mult)*max(1, count));
            word.clear();
            mult = 1;
            count = 0;
        }

        // processing
        sort(v.begin(), v.end());

        bool isUnbalanced = false;
        for (auto p: v) {
            if (p.second == 0)
                continue;

            if (!isUnbalanced) {
                cout << "Equation " << T << " is unbalanced.\n";
                isUnbalanced = true;
            }

            if (p.second < 0)
                cout << "You have destroyed " << -p.second << " atom" << (p.second == -1 ? "" : "s") << " of " << p.first << ".\n";
            else
                cout << "You have created " << p.second << " atom" << (p.second == 1 ? "" : "s") << " of " << p.first << ".\n";
        }

        if (!isUnbalanced)
            cout << "Equation " << T << " is balanced.";
        cout << '\n';

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