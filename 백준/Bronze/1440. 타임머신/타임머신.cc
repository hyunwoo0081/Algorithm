#include <iostream>

using namespace std;

int main() {
    string s;
    int arr[3];
    int result = 0;
    
    cin >> s;
    
    arr[0] = (s[0]-'0') * 10 + (s[1]-'0');
    arr[1] = (s[3]-'0') * 10 + (s[4]-'0');
    arr[2] = (s[6]-'0') * 10 + (s[7]-'0');
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            
            int k = (0+1+2) - i - j;
            result += (1 <= arr[i] && arr[i] <= 12) && (0 <= arr[j] && arr[j] <= 59) && (0 <= arr[k] && arr[k] <= 59);
        }
    }
    cout << result;

    return 0;
}