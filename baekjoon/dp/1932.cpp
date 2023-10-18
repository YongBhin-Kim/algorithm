// 백준 dp 1932 (실1) 23.7.17

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 500
int n;
int tree[MAX][MAX];
int dp[MAX][MAX];

int main(void) {
    int res = 0;
    cin>>n;
    cin>>tree[0][0];
    dp[0][0] = tree[0][0];
    
    for (int i=1; i<=n-1; i++) {
        for (int j=0; j<=i; j++)
            cin>>tree[i][j];
        dp[i][0] = tree[i][0] + dp[i-1][0];
        dp[i][i] = tree[i][i] + dp[i-1][i-1];
        for (int j=1; j<=i-1; j++)
            dp[i][j] = tree[i][j] + max(dp[i-1][j-1], dp[i-1][j]);   
    }

    for (int i=0; i<n; i++)
        res = max(dp[n-1][i], res);
    cout << res << endl;
}