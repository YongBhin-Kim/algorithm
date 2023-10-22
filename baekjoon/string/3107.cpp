// 23.8.21 IPv6 (G5)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string s, ss;
string ret;
vector<int> pos;

int main() {
    int prev, curr;
    prev = curr = 0;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if ( s[i] == ':' ) {
            pos.push_back(i);
        }
    }
    for (auto it = pos.begin(); it != pos.end(); it++)
        cout << *it << endl;
    
    for (int i=0; i<8; i++) {
        if ((pos[i]%5)<4)
            s.insert(pos[i])
    }

    return 0;
}

0025:0009:
// 0 -> 4 -> 9 -> 