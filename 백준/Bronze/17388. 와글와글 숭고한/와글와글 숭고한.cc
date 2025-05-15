#include <iostream>

using namespace std;

int main() {
    int HKS[3], idx = 0, sum = 0;
    string s[] = {"Soongsil", "Korea", "Hanyang"};
    
    for (int i = 0; i < 3; i++) {
        cin >> HKS[i];
        sum += HKS[i];
        if (HKS[idx] > HKS[i]) idx = i;
    }
    
    if (sum >= 100)
        cout << "OK";
    else
        cout << s[idx];
    

    return 0;
}