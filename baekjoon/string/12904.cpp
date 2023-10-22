// 23.8.21 12904 A와 B (G5)

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string s1, s2;

int num_a(string &s) {
    int cnt = 0;
    for (int i=0; i<s.length(); i++)
        if (s[i] == 'A') cnt++;
    return cnt;
}

int num_b(string &s) {
    return s.length() - num_a(s);
}

int ret = 0;
int main() {

    cin >> s1 >> s2;

    // [] || A
    // [].reverse || B

    int na = num_a(s1) - num_a(s2);
    int nb = num_b(s1) - num_b(s2);

    int i;
    int cnt = 0;
    while (cnt < (s2.length() - s1.length())) {
        for (i=s2.length(); i>=0; i--) {
            if ( s2[i] == 'B' )
                break; // ABBBBB
        }
        s2.resize(i+1);
        if (s1.compare(s2) == 0)
            break;
        for (i=s1.length(); i>=0; i--) {
            if ( s1[i] == 'B' )
                break; // ABBBBB
        }
        s1.resize(i+1);
        if (s1.compare(s2) == 0)
            break;

        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        cout << s1 << " " << s2 << endl;

        if (s1.length() == s2.length()) 
            ret = 1;
            break;
        cnt++;
    }
    cout << ret;


    return 0;
}