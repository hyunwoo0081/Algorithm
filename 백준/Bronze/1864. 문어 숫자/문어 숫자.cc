#include <iostream>
#include <unordered_map>

using namespace std;

void solution() {
  long long result, r;
  string s;
  unordered_map<char, int> maps;

  maps['-'] = 0;
  maps['\\'] = 1;
  maps['('] = 2;
  maps['@'] = 3;
  maps['?'] = 4;
  maps['>'] = 5;
  maps['&'] = 6;
  maps['%'] = 7;
  maps['/'] = -1;


  cin >> s;
  while (s != "#") {
    r = 1;
    result = 0;
    for (long long i = s.length()-1; i >= 0; i--) {
      result += maps[s[i]] * r;
      r *= 8;
    }
    cout << result << '\n';

    cin >> s;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}