#include <iostream>
#include <vector>

using namespace std;

vector<string> q;

void solution() {
    int N;
    string s;

    cin >> N;
    while (N--) {
        cin >> s;
        if (s == "READ") {
            cout << q.back() << '\n';
            q.pop_back();
        }
        else {
            q.push_back(s);
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