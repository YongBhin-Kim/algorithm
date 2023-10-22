// 23.8.21 문자열 게임 2 (G5) 
// 시간 초과

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// s = superaquatornado
// k = 2
// 3. 어떤 문자를 2개 포함하는 가장 작은 부분문자열
// 4. 어떤 문자를 2개 포함하면서 처음과 끝이 어떤 문자인 가장 긴 부분문자열

int t, k;
string s;
bool ret1_check = false;
int ret1, ret2;


void solve() {
    string ss;
    for (int window=k; window<=s.length(); window++) {
        for (int start=0; start+window<=s.length(); start++) {
            ss = s.substr(start, window);
            if ( (count(ss.begin(), ss.end(), ss[0]) == k) && (ret1 == false) ) {
                ret1 = ss.length();
                ret1_check = true;
            }
            if ( (ss[0] == ss[ss.length()-1]) && (count(ss.begin(), ss.end(), ss[0]) == k) ) {
                ret2 = ss.length();
            }
        }
    }
}

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        cin >> k;
        solve();
        if ( ret1_check == false ) {
            cout << -1 << endl;
        }
        else {
            cout << ret1 << " " << ret2 << endl;
            ret1_check = false;
        }
    }

    return 0;
}