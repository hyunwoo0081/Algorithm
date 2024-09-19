#include <iostream>

using namespace std;

int main() {
    int mw, mb, tw, tb, pw, pb, sw, sb;
    
    cin >> mw >> mb >> tw >> tb >> pw >> pb;
    
    sw = min(tw, min(mb, pb));
    sb = min(tb, min(mw, pw));
    
    if (sw > sb)
        cout << 2 * sb + 1;
    else if (sw < sb)
        cout << 2 * sw + 1;
    else
        cout << 2 * sw;

    return 0;
}