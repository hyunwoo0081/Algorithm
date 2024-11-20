#include <iostream>
#define SIZE 100

using namespace std;

bool visited[SIZE] = {false};
string words[SIZE];

bool isStart(string &target, string &word, int start) {
    if (target.length() - start < word.length())
        return false;

    for (int i = 0; i < word.length(); i++) {
        if (target[start+i] != word[i])
            return false;
    }
    return true;
}

void solution() {
    int N;
    string s;

    cin >> s >> N;
    for (int i = 0; i < N; i++)
        cin >> words[i];

    for (int i = 0; i < N; i++) {
        if (isStart(s, words[i], 0))
            visited[words[i].length()-1] = true;
    }

    for (int t = 1; t < N && !visited[N-1]; t++) {
        for (int v = 0; v < s.length(); v++) {
            if (!visited[v]) continue;

            for (int i = 0; i < N; i++) {
                if (isStart(s, words[i], v+1))
                    visited[v + words[i].length()] = true;
            }
        }
    }

    cout << visited[s.length()-1];
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}