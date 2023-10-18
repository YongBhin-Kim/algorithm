// 팰린드롬(dp) G4 v230731

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, s, e;
int a[2001]; 
int dp[2001][2001]; 

int main() {

    cin >> n;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }
    for (int i=1; i<n; i++) {
        dp[i][i] = 1;
        dp[i][i+1] = a[i]==a[i+1]? 1:0;
    }
    dp[n][n]=1;

    for (int i=1; i+2<=n; i++) {
        dp[i][i+2] = a[i]==a[i+2]?1:0;
    }

    for (int i=3; i<n; i++) { 
        for (int j=1; j+i<=n; j++) {
            dp[j][j+i] = dp[j+1][j+i-1] & (a[j]==a[j+i]); 
        }
    }

    cin >> m;
    for (int t=0; t<m; t++) { 
        cin >> s >> e; 
        cout << dp[s][e] << '\n';
    }


    return 0;
}