#include <iostream>

using namespace std;

string arr[] = {
    " @@@   @@@ ",
    "@   @ @   @",
    "@    @    @",
    "@         @",
    " @       @ ",
    "  @     @  ",
    "   @   @   ",
    "    @ @    ",
    "     @     "  
};

int main() {
    int N;
    
    cin >> N;
    
    for (string s : arr) {
        for (int i = 0; i < N; i++) {
            cout << s << ' ';
        }
        cout << '\n';
    }

    return 0;
}