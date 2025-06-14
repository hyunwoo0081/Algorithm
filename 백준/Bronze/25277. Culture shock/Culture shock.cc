#include <iostream>

using namespace std;

int main() {
    int N, result = 0;
    string s;
    
    cin >> N;
    while(N--) {
        cin >> s;
        result += s == "he" || s == "him" || s == "she" || s == "her";
    }
    
    cout << result;

    return 0;
}