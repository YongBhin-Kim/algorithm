// 23.8.21 문자열 게임 2 (G5) 
// 정답

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
int ret1, ret2;
int cnt[26]; // a to z

void solve() {
    ret1 = __INT_MAX__;
    ret2 = -1;

    for (int i=0; i<s.length(); i++) {
        cnt[s[i] - 'a']++;
    }
    
    for (int i=0; i<s.length(); i++) {
        if ( cnt[s[i] - 'a'] < k ) continue; 

        int temp = 0;
        // s[i]부터 시작
        for (int j=i; j<s.length(); j++) {
            if ( s[j] == s[i] ) 
                temp++;
            if (temp == k) {
                ret1 = min(ret1, j-i+1);
                ret2 = max(ret2, j-i+1);
                break;
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
        if ( ret1 == __INT_MAX__ || ret2 == -1 )
            cout << -1 << endl;
        else {
            cout << ret1 << " " << ret2 << endl;
        }
    }

    return 0;
}