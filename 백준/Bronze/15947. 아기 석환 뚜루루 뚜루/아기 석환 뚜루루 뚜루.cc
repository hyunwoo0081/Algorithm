#include <iostream>

using namespace std;

const string loop[] = {"baby", "sukhwan", "tururu", "tu",
                    "very", "cute", "tururu", "tu",
                    "in", "bed", "tururu", "tu",
                    "baby", "sukhwan"};

void solution() {
    int N, k, v;

    cin >> N;
    N--;
    k = N/14 + 1;
    v = N%14;
    if (v % 4 == 3 || v % 4 == 2) {
        if (v % 4 == 2) k++;

        if (k >= 5)
            cout << "tu+ru*" << k;
        else {
            cout << "tu";
            for (int i = 0; i < k; i++)
                cout << "ru";
        }
    }
    else
        cout << loop[v];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}