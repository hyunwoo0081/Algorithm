#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, double> costs;

void solution() {
    string s;
    double result;

    costs["Paper"] = 57.99;
    costs["Printer"] = 120.50;
    costs["Planners"] = 31.25;
    costs["Binders"] = 22.50;
    costs["Calendar"] = 10.95;
    costs["Notebooks"] = 11.20;
    costs["Ink"] = 66.95;

    cin >> s;
    while (s != "EOI") {
        result += costs[s];
        cin >> s;
    }

    cout << fixed;
    cout.precision(2);
    cout << '$' << result;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();
}