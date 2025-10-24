#include <iostream>

using namespace std;

bool map[3][3];

bool isSame(bool map[3][3]) {
    bool first = map[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] != first)
                return false;
        }
    }
    return true;
}

bool make(bool init[3][3], int action) {
    bool map[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            map[i][j] = init[i][j];
        }
    }
    
    if (action & (1<<6)) {
        for (int i = 0; i < 3; i++)
            map[i][i] = !map[i][i];
    }
    if (action & (1 << 7)) {
        for (int i = 0; i < 3; i++)
            map[2-i][i] = !map[2-i][i];
    }
    
    for (int i = 0; i < 3; i++) {
        if (action & (1 << i)) {
            for (int j = 0; j < 3; j++)
                map[i][j] = !map[i][j];
        }
    }
    
    for (int i = 3; i < 6; i++) {
        if (action & (1 << i)) {
            for (int j = 0; j < 3; j++)
                map[j][i-3] = !map[j][i-3];
        }
    }
    
    return isSame(map);
}

int bitcount(int action) {
    int result = 0;
    for (int i = 0; i < 31; i++) {
        if (action & (1 << i)) {
            result++;
        }
    }
    
    return result;
}


int main() {
    int T, N, r;
    char c;
    
    cin >> T;
    cin.ignore();
    while (T--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> c;
                map[i][j] = c == 'T';
            }
        }
        
        r = 987654321;
        for (int i = 0; i < (1<<8); i++) {
            if (!make(map, i)) continue;
            r = min(r, bitcount(i));
        }
        
        cout << (r < 10 ? r : -1) << '\n';
    }

    return 0;
}