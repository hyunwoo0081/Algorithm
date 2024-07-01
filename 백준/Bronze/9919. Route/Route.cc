#include <iostream>

using namespace std;

int getType(int prev, int now) {
    if (prev == now)
        return 0;
    else if (prev < now)
        return 1;
    return 2;
}

int main() {
    int N, prevA, A, prevType, nowType, firstA, firstType, result[3] = {0};
    
    cin >> N >> prevA >> A;
    N -= 2;
    firstType = prevType = getType(prevA, A);
    result[prevType]++;
    firstA = prevA;
    prevA = A;
    
    while (N--) {
        cin >> A;
        nowType = getType(prevA, A);
        
        if (prevType != nowType)
            result[nowType]++;
        
        prevA = A;
        prevType = nowType;
    }
    
    nowType = getType(prevA, firstA);
    if (prevType != nowType)
        result[nowType]++;
    
    
    for (auto r : result) {
        cout << r << ' ';
    }

    return 0;
}