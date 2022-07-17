#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char oper[9];
char dOper[] = {'+', ' ', '-'};
vector<string> arr;

void save0eq(int N, int depth) {
    if (depth == N) {
        int f = 0;
        int spaceNum = 1;

        for (int i = 2; i <= N; i++) {
            if (oper[i-1] == ' ') {
                spaceNum = spaceNum*10 + (spaceNum >= 0 ? i : -i);
            }
            else {
                f += spaceNum;
                spaceNum = oper[i-1] == '+' ? i : -i;
            }
        }
        f += spaceNum;


        if (f == 0) {
            arr.push_back("");
            for (int i = 1; i < N; i++) {
                arr[arr.size()-1].push_back(i+'0');
                arr[arr.size()-1].push_back(oper[i]);
            }
            arr[arr.size()-1].push_back(N+'0');
        }
        return;
    }

    for (auto op : dOper) {
        oper[depth] = op;
        save0eq(N, depth + 1);
    }
}

void solution() {
    int Tc, N;
    cin >> Tc;
    while (Tc--) {
        arr.clear();
        cin >> N;
        save0eq(N, 1);

        sort(arr.begin(), arr.end());
        for (auto s: arr)
            cout << s << '\n';
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}