#include <iostream>
#include <cstring>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Trie {
    bool isTerminate = false;
    Trie *next[10];

    Trie() {
        memset(next, 0, sizeof(next));
    }

    ~Trie() {
        for (auto & child : next)
            delete child;
    }
};

bool addList(Trie *trie, string &num) {
    bool isPassed = true;
    for (char c: num) {
        if (trie->isTerminate) return true;

        if (trie->next[c-'0'] == nullptr) {
            trie->next[c-'0'] = new Trie();
            isPassed = false;
        }
        trie = trie->next[c-'0'];
    }
    trie->isTerminate = true;

    return isPassed;
}

void solution() {
    int T, N;
    Trie *nums;
    string inputs;

    cin >> T;
    while (T--) {
        cin >> N;
        nums = new Trie();
        bool isMatched = false;
        while (N--) {
            cin >> inputs;
            isMatched |= addList(nums, inputs);
        }
        delete nums;
        cout << (isMatched ? "NO\n" : "YES\n");
    }
}

int main() {
    fastIO();
    solution();

    return 0;
}