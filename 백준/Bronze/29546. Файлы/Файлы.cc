#include <iostream>
#define SIZE 1000

using namespace std;

string names[SIZE];

int main() {
    int N, T, s, e;
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> names[i];
    
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> s >> e;
        for (; s <= e; s++)
            cout << names[s-1] << '\n';
    }

    return 0;
}