// # 2*n 타일링
// # dp[n] = dp[n-2] = dp[n-1]
#include <stdio.h>
int main() {

    int dp[1001]; int n;
    scanf("%d", &n);
    dp[0]=0; dp[1]=1; dp[2]=2;
    for (int i=3; i<n+1; i++) {
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    printf("%d\n", dp[n]);
    return 0;
}