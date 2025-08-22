#include <iostream>
#define SIZE 100

using namespace std;

bool park[SIZE];

int main() {
    string s;
    int N;
    
    cin >> N;
    for (int i = 0; i < N; i++) park[i] = true;
    
    for (int t = 0; t < 2; t++) {
        cin >> s;
        for (int i = 0; i < N; i++) {
            park[i] &= s[i] == 'C';
        }
    }
    
    int result = 0;
    for (int i = 0; i < N; i++) result += park[i];
    cout << result;

    return 0;
}