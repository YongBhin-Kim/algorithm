// 23.8.21 문자열 게임 2 (G5) 
// 투 포인터

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// s = superaquatornado
// k = 2
// 3. 어떤 문자를 2개 포함하는 가장 작은 부분문자열 (의 길이)
// 4. 어떤 문자를 2개 포함하면서 처음과 끝이 어떤 문자인 가장 긴 부분문자열 (의 길이)

int t, k;
string s;
int ret1, ret2;

void solve() {
    ret1 = __INT_MAX__;
    ret2 = -1;

    vector<int> inx[26]; // 해당 알파벳의 string에서의 인덱스 배열

    for (int i=0; i<s.length(); i++) {
        inx[s[i] - 'a'].push_back(i);
    }

#if 1
    for (int i=0; i<26; i++) { 
        printf("%c : ", i + 'a');
        for (auto it = inx[i].begin(); it != inx[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
#endif
     
    int left_pointer, right_pointer;
    for (int a=0; a<26; a++) {

        if (inx[a].size() < k) continue;
        
        left_pointer = 0;
        right_pointer = k-1;

        do {
            ret1 = min(ret1, inx[a][right_pointer] - inx[a][left_pointer] + 1);
            ret2 = max(ret2, inx[a][right_pointer] - inx[a][left_pointer] + 1);
            right_pointer++;
            left_pointer++;
        } while ( right_pointer < inx[a].size() );
        
    }
    
}

int main() {
    cin >> t;
    while(t--) {
        cin >> s;
        cin >> k;
        solve();
        if ( ret1 == __INT_MAX__  )
            cout << -1 << endl;
        else {
            cout << ret1 << " " << ret2 << endl;
        }
    }

    return 0;
}