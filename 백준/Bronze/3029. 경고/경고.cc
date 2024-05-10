#include <iostream>

using namespace std;

int getSecond(string time) {
  int hour = stoi(time.substr(0, 2));
  int minute = stoi(time.substr(3, 2));
  int second = stoi(time.substr(6, 2));

  return hour * 3600 + minute * 60 + second;
}

string getTime(int second) {
  int hour = second / 3600;
  int minute = (second % 3600) / 60;
  int sec = second % 60;

  string time = "";
  if (hour < 10) time += "0";
  time += to_string(hour) + ":";
  if (minute < 10) time += "0";
  time += to_string(minute) + ":";
  if (sec < 10) time += "0";
  time += to_string(sec);

  return time;
}

void solution() {
  string start, end;
  const int MAX = 86400;

  cin >> start >> end;
  int startSecond = getSecond(start);
  int endSecond = getSecond(end);

  if (startSecond >= endSecond) endSecond += MAX;

  int duration = endSecond - startSecond;
  cout << getTime(duration) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solution();
}