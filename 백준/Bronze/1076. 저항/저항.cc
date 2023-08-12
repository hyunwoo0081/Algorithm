#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> colors;

void solution() {
    long long result = 0;

    string s;
    colors["black"] = 0;
    colors["brown"] = 1;
    colors["red"] = 2;
    colors["orange"] = 3;
    colors["yellow"] = 4;
    colors["green"] = 5;
    colors["blue"] = 6;
    colors["violet"] = 7;
    colors["grey"] = 8;
    colors["white"] = 9;

    cin >> s;
    result += colors[s] * 10;
    cin >> s;
    result += colors[s];
    cin >> s;

    for (int i = 0; i < colors[s]; i++)
        result *= 10;
    cout << result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}