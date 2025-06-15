#include <iostream>

using namespace std;

int main() {
    int N, oxygen=0, ocean=0, temperature=-30;
    string t, d;
    
    cin >> N;
    while (N--) {
        cin >> t >> d;
        if (t == "oxygen")
            oxygen += d[1]-'0';
        else if (t == "ocean")
            ocean += d[1]-'0';
        else if (t == "temperature")
            temperature += d[1]-'0';
    }
    
    if (oxygen >= 14 && ocean >= 9 && temperature >= 8)
        cout << "liveable";
    else
        cout << "not liveable";

    return 0;
}