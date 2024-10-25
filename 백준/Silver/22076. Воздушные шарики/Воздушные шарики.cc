#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> cnts;
void solution() {
    int N, K, a;

    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> a;
        cnts[a] += 1;
    }

    for (auto cnt : cnts) {
        if (K > 0) {
            cout << cnt.first << ' ';
            K--;
            cnts[cnt.first] = cnt.second - 1;
        }
    }

    for (auto cnt : cnts) {
        if (K > 0 && cnt.second > 0) {
            for (int i = 0; i < min(K, cnt.second); i++)
                cout << cnt.first << ' ';
            K -= cnt.second;
        }
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}