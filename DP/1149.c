// [R] [G] [B]

#include <stdio.h>

int dp[1000][3];
int min(int a, int b) {
    return a<b ? a:b;
}

int main() {
    
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d", &dp[i][j]); }}

    for (int i=1; i<n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + dp[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + dp[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + dp[i][2]; }

    printf("%d",min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]));

    return 0;
}