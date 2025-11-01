#include <iostream>
#define SIZE 100

using namespace std;

int maps[SIZE][SIZE];
int stack[SIZE];
int stackSize = 0;
int main() {
    int T, N, M;
    
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> maps[y][x];
            }
        }
        
        stackSize = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (maps[y][x] == -1) continue;
                
                bool has = false;
                for (int i = 0; i < stackSize; i++)
                    has |= maps[y][x] == stack[i];
                if (has) continue;
                
                has = false;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) continue;
                        
                        int nx = x + dx;
                        int ny = y + dy;
                        if (0 <= nx && nx < M && 0 <= ny && ny < N)
                            has |= maps[ny][nx] == maps[y][x];
                    }
                }
                
                if (has)
                    stack[stackSize++] = maps[y][x];
            }
        }
        
        cout << stackSize << '\n';
    }

    return 0;
}