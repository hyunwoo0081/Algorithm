#include <iostream>

using namespace std;

int dx[] = {0, 1, 0, -1, 0};
int dy[] = {0, 0, 1, 0, -1};

bool isEmpty(bool map[10][10]) {
  bool empty = true;
  for (int y = 0; y < 10; y++)
    for (int x = 0; x < 10; x++)
      empty &= !map[y][x];
  return empty;
}

int getGreadyTrial(bool map[10][10]) {
  int nx, ny, count = 0;
  for (int y = 1; y < 10; y++) {
    for (int x = 0; x < 10; x++) {
      if (map[y-1][x]) {
        count++;
        for (int i = 0; i < 5; i++) {
          nx = x + dx[i];
          ny = y + dy[i];
          if (0 <= nx && nx < 10 && 0 <= ny && ny < 10)
            map[ny][nx] = !map[ny][nx];
        }
      }
    }
  }
  return isEmpty(map) ? count : -1;
}

int getMinTrial (bool map[10][10]) {
  bool copiedMap[10][10];
  int f, nx, ny, count, result = -1;
  
  for (int brute = 0; brute < 1024; brute++) {
    for (int y = 0; y < 10; y++)
      for (int x = 0; x < 10; x++)
        copiedMap[y][x] = map[y][x];

    count = 0;
    for (int x = 0; x < 10; x++) {
      if (brute & (1 << x)) {
        count++;
        for (int i = 0; i < 5; i++) {
          nx = x + dx[i];
          ny = 0 + dy[i];
          if (0 <= nx && nx < 10 && 0 <= ny)
            copiedMap[ny][nx] = !copiedMap[ny][nx];
        }
      }
    }

    f = getGreadyTrial(copiedMap);
    if (f >= 0)
      result = result == -1 ? f+count : min(result, f+count);
  }

  return result;
}

void solution() {
  bool maps[10][10];
  string s;

  for (int y = 0; y < 10; y++) {
    cin >> s;
    for (int x = 0; x < 10; x++)
      maps[y][x] = s[x] == 'O';
  }

  cout << getMinTrial(maps);
}
 
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}