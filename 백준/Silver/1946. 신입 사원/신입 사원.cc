#include <iostream>
#include <algorithm>


using namespace std;

pair<int, int> arr[100000];

void solution() {
    int T, N, a, b;

    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            arr[i] = make_pair(a, b);
        }
        sort(arr, arr+N);

        int count = 1;
        int minNum = arr[0].second;
        for (int i = 1; i < N; i++) {
            if (minNum > arr[i].second) {
                count++;
                minNum = arr[i].second;
            }
        }
        cout << count << '\n';
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}