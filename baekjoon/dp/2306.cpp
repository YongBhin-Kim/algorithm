// 백준 2306 - 유전자(g3)
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std; 

int dp[501][501];
string s;
bool iskoi(char a, char b){
    if( (a=='a' && b=='t') || (a=='g' && b=='c') )
        return true;
    return false;
}
int main(){
    cin >> s;
    int n = s.length();

    for(int k=1; k<n; k++) { // k칸 떨어짐
        for(int i=0; i+k<n; i++) { // 시작 index
            if( iskoi(s[i], s[i+k]) ) {
                dp[i][i+k] = dp[i+1][i+k-1]+2; // i부터 i+k까지 떨어진 최대 koi 유전자 길이
            }
            for(int j=i; j<i+k; j++) {
                dp[i][i+k] = max(dp[i][i+k], dp[i][j] + dp[j+1][i+k]);
            }
        }
    }
    cout << dp[0][n-1];
}