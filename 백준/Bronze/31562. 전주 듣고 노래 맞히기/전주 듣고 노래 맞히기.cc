#include <iostream>
#define SIZE 1000

using namespace std;

string names[SIZE];
char starts[SIZE][3];

int main() {
    int N, M, T, i, j, k, cnt, index;
    char start[3], dummy;
    bool isMatch;
    
    cin >> N >> M;
    for (i = 0; i < N; i++) {
        cin >> T >> names[i];
        for (j = 0; j < 7; j++) {
            if (j < 3) cin >> starts[i][j];
            else cin >> dummy;
        }
    }
    
    for (i = 0; i < M; i++) {
        for (j = 0; j < 3; j++)
            cin >> start[j];
        
        index = cnt = 0;
        for (j = 0; j < N; j++) {
            isMatch = true;
            for (k = 0; k < 3; k++)
                if (starts[j][k] != start[k])
                    isMatch = false;
            
            if (isMatch) {
                cnt++;
                index = j;
            }
        }
        
        if (cnt == 1)
            cout << names[index] << '\n';
        else if (cnt == 0)
            cout << "!\n";
        else
            cout << "?\n";
    }

    return 0;
}