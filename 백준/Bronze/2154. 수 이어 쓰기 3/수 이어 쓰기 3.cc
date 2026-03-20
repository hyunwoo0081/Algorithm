#include <iostream>
#include <deque>

using namespace std;

deque<char> v;

bool startWith(string &s) {
    bool result = true;
    for (int i = 0; i < s.length(); i++) {
        result &= v[i] == s[i];
    }
    
    return result;
}

int stackSize = 0;
char stack[10];

int main() {
    string s;
    cin >> s;
    
    for (int i = 1; i < 10; i++) {
        v.push_back(i+'0');
    }
    
    int next = 10;
    int result = 1;
    while (!startWith(s)) {
        result++;
        v.pop_front();
        
        if (v.size() < s.length()) {
            int tmp = next++;
            
            stackSize = 0;
            while (tmp > 0) {
                stack[stackSize++] = tmp % 10;
                tmp /= 10;
            }
            
            while (stackSize > 0) {
                v.push_back(stack[--stackSize] + '0');
            }
        }
    }
    cout << result;

    return 0;
}