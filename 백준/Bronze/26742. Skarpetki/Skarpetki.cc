#include <iostream>
#define SIZE 30001

bool notPrime[SIZE] = {true, true};

using namespace std;

void solution() {
    string s;
    int b, c;

    cin >> s;
    b = c = 0;
    for (auto ch : s) {
        if (ch == 'B') b++;
        else c++;
    }

    cout << (b/2 + c/2);
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}