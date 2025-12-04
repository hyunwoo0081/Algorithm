#include <iostream>

using namespace std;

int main() {
    string s;
    
    while (true) {
        cin >> s;
        if (s == "animal")
            cout << "Panthera tigris\n";
        else if (s == "flower")
            cout << "Forsythia koreana\n";
        else if (s == "tree")
            cout << "Pinus densiflora\n";
        else if (s == "end")
            return 0;
    }
}