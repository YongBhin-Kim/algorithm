// 23.8.13 
// LCS - 1 (G5)
// 최장 공통 부분수열(Longest Common Subsequence)

#include <iostream>
#include <string>
using namespace std;

int dp[1001][1001];

int getLCS(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    for (int i=1; i<=len1; i++) {
        for (int j=1; j<=len2; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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

    cout << getLCS(s1, s2) << endl;


    return 0;
}

// ACAYKP
// CAPCAK