#include <iostream>

using namespace std;

int leftCount(int arr[]) {
    int count = 0;
    for (int i = 0; i < 4; i++)
        count += !!arr[i];
    
    return count;
}

int main() {
    int bowl[4], index, i, result;
    
    for (auto &b : bowl) cin >> b;
    while (leftCount(bowl)) {
        while (leftCount(bowl) > 1) {
            index = -1;
            for (i = 0; i < 4; i++) {
                if (bowl[i] != 0 && (index == -1 || bowl[i] < bowl[index]))
                    index = i;
            }
            
            for (i = 0; i < 4; i++) {
                if (i != index)
                    bowl[i] = max(0, bowl[i]-bowl[index]);
            }
        }
        
        result = 0;
        for (auto b : bowl)
            result += b;
        cout << result << '\n';
        
        for (auto &b : bowl) cin >> b;
    }

    return 0;
}