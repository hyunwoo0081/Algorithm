#include <iostream>
#define SIZE 10000
#define ll long long

using namespace std;


ll maps[SIZE];
void solution() {
    ll N, l, r, result = 0;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> maps[i];

    for (int i = 0; i < N; i++) {
        if (i == N-1 || maps[i] > maps[i + 1]) {
            l = r = i;
            while (l > 0 && maps[l] >= maps[l-1]) l--;
            while (r < N-1 && maps[r] >= maps[r+1]) r++;

            result = max(result, (r-l+1));
            i = r;
        }
    }

    cout << result << '\n';
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}