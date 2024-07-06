#include <iostream>
#include <string>

using namespace std;

int timeToMinutes(const string& time) {
    int hh = stoi(time.substr(0, 2));
    int mm = stoi(time.substr(3, 2));
    return hh * 60 + mm;
}

// Function to calculate the minimum number of button presses to adjust the clock
int minButtonPresses(const string& currentTime, const string& correctTime) {
    int currentMinutes = timeToMinutes(currentTime);
    int correctMinutes = timeToMinutes(correctTime);

    // Calculate the difference in minutes considering the wrap-around using modulo
    int difference = (correctMinutes - currentMinutes + 1440) % 1440;

    // Number of full hours and remaining minutes in the difference
    int numHours = difference / 60;
    int numMinutes = difference % 60;

    // The total number of button presses is the sum of hour presses and minute presses
    return numHours + numMinutes;
}

void solution() {
    string currentTime, correctTime;
    cin >> currentTime >> correctTime;

    int result = minButtonPresses(currentTime, correctTime);
    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solution();

    return 0;
}