#include <iostream>

using namespace std;

int main() {
    string s;
    int result = 0;
    
    while (getline(cin, s)) {
        result++;
    }
    cout << result;

    return 0;
}