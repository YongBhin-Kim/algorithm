// 23.8.13 
// LCS - 2 (G4)
// 최장 공통 부분수열(Longest Common Subsequence)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[1001][1001];

int getLCS(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    for (int i=1; i<=len1; i++) {
        for (int j=1; j<=len2; j++) {
            if ( s1[i-1] == s2[j-1] ) {
                dp[i][j] = dp[i-1][j-1] + 1;
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

#if 1
    cout << "    ";
    for (int i=0; i<s2.length(); i++) {
        cout << " " << s2[i];
    }
    cout << endl << "  ";
    for (int i=0; i<=s1.length(); i++) {
        for (int j=0; j<=s2.length(); j++) {
            cout << " " << dp[i][j];
        }
        cout << endl;
        cout << s1[i] << " ";
    }
#endif

    string ret;
    int i = s1.length();
    int j = s2.length();

    // 1. dp[i][j] == dp[i][j-1]
    // 2. dp[i][j] == dp[i-1][j]
    // 3. dp[i][j] == dp[i-1][j-1]
    while( i!=0 && j!=0 ) {
        if ( dp[i][j] == dp[i][j-1] ) {
            j--;
        }
        else if ( dp[i][j] == dp[i-1][j] ) {
            i--;
        }
        else {
            ret += s1[i-1];
            i--; j--;
        }
    }
    if ( ret.length() > 0 ) {
        reverse(ret.begin(), ret.end());
        cout << ret;
    }

    return 0;
}


// ACAYKP
// CAPCAK