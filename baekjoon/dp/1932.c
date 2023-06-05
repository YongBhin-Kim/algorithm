#include <stdio.h>

int t[501][501];
int dp[501][501];
int ans=0;

int max(int a, int b) {
    return (a>b) ? a:b;
}


int main() {
    int n;
    scanf("%d",&n);
    scanf("%d",&t[0][0]);
    dp[0][0]=t[0][0];

    for(int i=1; i<n; i++) {
        for(int j=0; j<=i; j++) {
            scanf("%d",&t[i][j]);
        }
        dp[i][0] = t[i][0]+dp[i-1][0]; // 처음꺼
        if (i>1){
            for(int k=1; k<i; k++) {
                dp[i][k]= t[i][k] + max(dp[i-1][k-1],dp[i-1][k]);}}
        dp[i][i] = t[i][i]+dp[i-1][i-1]; // 마지막꺼
    }
    for (int j=0; j<n-1; j++) {
        if (ans < max(dp[n-1][j], dp[n-1][j+1])) {
            ans=max(dp[n-1][j],dp[n-1][j+1]);
        }
    }
    printf("%d\n",ans);

    return 0;
}