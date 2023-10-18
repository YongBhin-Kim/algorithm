// 쇠막대기(S2)
// 스택

#include <iostream>
#include <string>
#include <stack>
using namespace std;

long long solution(string s) {
    stack<char> x;
    long long Answer = 0;

    for ( int i=0; i<s.length(); i++ ) {
        if ( s[i] == '(' ) {
            if ( (!x.empty()) && x.top() == ')' ) {
                x.pop();
            }
            x.push('(');
        }
        else if ( s[i] == ')' ) {
            if ( x.top() == '(' ) { // 레이저 발사. 스택의 개수 '('의 개수만큼 추가
                x.pop();
                Answer += x.size();
                x.push(')');
            }
            else if ( x.top() == ')' ) { // 막대기 감소
                Answer++;
                x.pop();
                if ( !x.empty() ) {
                    x.pop(); 
                    x.push(')');
                }
                else break;
            }
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

    return 0;
}