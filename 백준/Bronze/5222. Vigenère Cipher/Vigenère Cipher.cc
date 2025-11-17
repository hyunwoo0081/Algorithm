#include <iostream>

using namespace std;

int main() {
    int N;
    string a, b;
    
    cin >> N;
    while (N--) {
        cin >> a >> b;
        cout << "Ciphertext: ";
        for (int i = 0; i < b.length(); i++) {
            cout << (char)(((a[i % a.length()]-'A' + b[i]-'A')%26)+'A');
        }
        
        cout << '\n';
    }

    return 0;
}