#include <iostream>

using namespace std;

void solution() {
  string s;

  cin >> s;
  if (s == "SONGDO")
    cout << "HIGHSCHOOL";
  else if (s == "CODE")
    cout << "MASTER";
  else if (s == "2023")
    cout << "0611";
  else if (s == "ALGORITHM")
    cout << "CONTEST";
}
 
int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}