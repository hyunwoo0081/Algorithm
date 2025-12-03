#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    switch(s[0]) {
        case 'F':
            cout << "Foundation";
            break;
        case 'C':
            cout << "Claves";
            break;
        case 'V':
            cout << "Veritas";
            break;
        case 'E':
            cout << "Exploration";
            break;
    }

    return 0;
}