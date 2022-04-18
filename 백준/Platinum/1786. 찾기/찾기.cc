#include <iostream>
#include <vector>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string T, P;
int Ks[1000000] = {0};
vector<int> matched;

void solution() {
    getline(cin, T);
    getline(cin, P);

    //K 구하기
    int j = 0;
    for (int i = 1; i < P.size(); ++i) {
        while (j > 0 && P[i] != P[j])
            j = Ks[j-1];

        if (P[i] == P[j])
            Ks[i] = ++j;
    }

    //문자열 찾기
    int pi = 0;
    for (int ti = 0; ti < T.size(); ++ti) {
        while (pi > 0 && T[ti] != P[pi])
            pi = Ks[pi-1];

        if (T[ti] == P[pi]) pi++;

        if (pi == P.size()) {
            matched.emplace_back(ti-pi+2);
            pi = Ks[pi-1];
        }
    }


    cout << matched.size() << '\n';
    for (int index: matched) {
        cout << index << ' ';
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}