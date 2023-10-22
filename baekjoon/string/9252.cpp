// 23.8.13 
// LCS - 2 (G4)
// 최장 공통 부분수열(Longest Common Subsequence)

#include <iostream>
#include <string>
using namespace std;

#if 1
string dp[1001][1001];

string getLCS(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    for (int i=1; i<=len1; i++) {
        for (int j=1; j<=len2; j++) {
            if ( s1[i-1] == s2[j-1] ) {
                dp[i][j] = dp[i-1][j-1] +  s1[i-1];
            }
            else {
                dp[i][j] = dp[i][j-1].length() > dp[i-1][j].length() ? dp[i][j-1] : dp[i-1][j];
            }
        }
    }
    return dp[len1][len2];
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    string ret = getLCS(s1, s2);    

    cout << ret.length() << endl;
    cout << ret << endl;

    return 0;
}
#endif


// ACAYKP
// CAPCAK