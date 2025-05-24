#include <iostream>

using namespace std;

int num[16];

int main() {
    string s;
    int sum = 0;
    
    cin >> s;
    for (int i = 0; i < 16; i++) {
        num[i] = s[i]-'0';
        if (i % 2 == 0) num[i] *= 2;
        num[i] = num[i]/10 + num[i]%10;
        sum += num[i];
    }

    cout << (sum%10 == 0 ? "DA" : "NE");

    return 0;
}