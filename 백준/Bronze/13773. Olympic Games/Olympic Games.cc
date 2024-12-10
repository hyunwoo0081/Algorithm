#include <iostream>

using namespace std;

void solution() {
    int n;

    cin >> n;
    while (n != 0) {
        cout << n << " ";
        if (n < 1896 || (n-1896)% 4 != 0)
            cout << "No summer games\n";
        else if (1914 <= n && n <= 1918 || 1939 <= n && n <= 1945)
            cout << "Games cancelled\n";
        else if (n < 2024)
            cout << "Summer Olympics\n";
        else
            cout << "No city yet chosen\n";

        cin >> n;
    }
}

int main(){
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    solution();

    return 0;
}