#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, int> table;
char newcleos[4] = {'A', 'C', 'G', 'T'};
vector<string> arr;

void solution() {
    int N, M, count;
    string s, result;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> s;
        arr.push_back(s);
    }

    for (int i = 0; i < 4; i++)
        table[newcleos[i]] = i;

    count = 0;
    for (int i = 0; i < M; i++) {
        int counts[] = {0, 0, 0, 0};

        for (int j = 0; j < N; j++)
            counts[table[arr[j][i]]]++;

        int maxIndex = 0;
        for (int j = 0; j < 4; j++)
            if (counts[maxIndex] < counts[j])
                maxIndex = j;

        result += newcleos[maxIndex];
        for (int j = 0; j < 4; j++)
            count += (maxIndex != j) * counts[j];
    }

    cout << result << '\n' << count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}