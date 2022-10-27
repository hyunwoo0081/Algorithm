#include <iostream>
#include <vector>

using namespace std;

vector<int> stack;
bool isSelected[51] = {false};

bool find(string &input, int index, int maxNum) {
    if (index == input.length())
        return true;

    int num = 0;
    for (int i = index; i < input.length(); i++) {
        num = num*10 + input[i]-'0';
        if (num > maxNum)
            return false;
        if (isSelected[num])
            continue;

        stack.push_back(num);
        isSelected[num] = true;

        if(find(input, i+1, maxNum))
            return true;
        stack.pop_back();
        isSelected[num] = false;
    }
    return !isSelected[num];
}

void solution() {
    int N;
    string input;
    stack.reserve(50);

    cin >> input;
    if (input.length() < 10)
        N = input.length();
    else
        N = (input.length() - 9)/2 + 9;

    find(input, 0, N);
    for (auto s: stack)
        cout << s << ' ';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solution();

    return 0;
}
