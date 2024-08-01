#include <iostream>

using namespace std;

int main() {
    string s;
    int a;
    bool isLeft = true;
    
    cin >> s;
    while (s != "99999") {
        a = s[0] + s[1] - '0' - '0';
        if (a % 2 == 0 && a != 0)
            isLeft = false;
        else if (a % 2)
            isLeft = true;
            
        cout << (isLeft ? "left " : "right ");
        cout << s[2] << s[3] << s[4] << '\n';
        
        cin >> s;
    }

    return 0;
}