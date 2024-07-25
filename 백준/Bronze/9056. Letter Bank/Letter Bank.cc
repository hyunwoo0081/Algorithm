#include <iostream>
#define SIZE 26

using namespace std;

bool a[SIZE] = {false};
bool b[SIZE] = {false};

int main() {
    int T;
    string A, B;
    bool result;
    
    cin >> T;
    while (T--) {
        cin >> A >> B;
        
        for (int i = 0; i < SIZE; i++)
            a[i] = b[i] = false;
        
        for (auto c: A)
            a[c - 'A'] = true;
        for (auto c: B)
            b[c - 'A'] = true;
        
        result = true;
        for (int i = 0; i < SIZE; i++)
            result &= a[i] == b[i];
            
        cout << (result ? "YES\n" : "NO\n");
    }

    return 0;
}