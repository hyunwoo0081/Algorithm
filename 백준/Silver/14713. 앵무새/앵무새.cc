#include <iostream>
#define SIZE 100

using namespace std;

string arr[SIZE];
int idx[SIZE] = {0};

void solution() {
    int N, i, j, k, ldx = 0;
    string l;
    bool isMatch = false;

    cin >> N;
    cin.ignore();
    for (i = 0; i < N; i++) {
        getline(cin, arr[i]);
    }
    getline(cin, l);

    while (ldx < l.length()) {
        isMatch = false;
        for (k = 0; k < N; k++) {
            // 판단
            i = ldx, j = idx[k];
            while (i < l.length() && j < arr[k].length() && l[i] == arr[k][j] && l[i] != ' ') {
                i++, j++;
            }

            if ((i == l.length() || l[i] == ' ') && (j == arr[k].length() || arr[k][j] == ' ')) {
                ldx = i + 1;
                idx[k] = j + 1;
                isMatch = true;
                break;
            }
        }

        if (!isMatch)
            break;
    }

    for (k = 0; k < N; k++) {
        isMatch &= idx[k] >= arr[k].length();
    }

    cout << (isMatch ? "Possible" : "Impossible");
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}