// 쇠막대기(S2)
// 스택 안쓰고

#include <iostream>
#include <stack>
using namespace std;

long long solution(string s) {
    long long Answer = 0;

    // stack<int> v;
    // v.push(s[0]); // (
    long long v = 1;

    for ( int i=1; i<s.length(); i++ ) {
        // s[i-1] == ')' or '('
        if ( s[i] == ')' ) {
            v--;
            if ( s[i-1] == '(' ) // 레이저 발사
                Answer += v;
            else // 막대기 감소
                Answer += 1;
        }
        else { // '('
            v++;
        }
    }


    return Answer;
}

int main() {
    string s;
    cin >> s;
    long long Answer;
    Answer = solution(s);
    cout << Answer;
}