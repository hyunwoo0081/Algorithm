#include <iostream>

using namespace std;

string results[] = {
    "11\nA B C D E F G H J L M",
    "9\nA C E F G H I L M",
    "9\nA C E F G H I L M",
    "9\nA B C E F G H L M",
    "8\nA C E F G H L M",
    "8\nA C E F G H L M",
    "8\nA C E F G H L M",
    "8\nA C E F G H L M",
    "8\nA C E F G H L M",
    "8\nA B C F G H L M",
};

void solution() {
    int N;

    cin >> N;
    cout << results[N-1];
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}