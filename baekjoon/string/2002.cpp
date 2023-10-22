// 23.8.21 추월 (S1)

// 1 2 3 4 -> 4 1 2 3 (i=0 j=3)
// 1 

// 1 2 3 4 5 -> 2 5 4 1 3
// 3

// 자신의 뒤에 자신보다 작은 숫자가 존재하면 추월
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n;
string s1[1000], s2[1000];
int ret;

int inx(string &s) {
    for (int i=0; i<n; i++) {
        if (s == s1[i])
            return i;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> s1[i];
    }
    for (int i=0; i<n; i++) {
        cin >> s2[i];
    }
    // 자신보다 뒤에 자신보다 작은 게 있다면
    for (int i=0; i<n-1; i++) {
        for (int k=i+1; k<n; k++) {
            if ( inx(s2[i]) > inx(s2[k]) ) {
                ret++;
                break;
            }
        }
    }

    cout << ret;
}
