// # # 계단 오르기

// # # dp = [0 10 20 15 25 10 20]
// # # 10 -> 20 -> 25 -> 20

// # # dp[n] = num[n-1]+dp[n-3] vs dp[n-2]

#include <stdio.h>

#define max(a,b) (a>b ? a:b)

int main() {
    int n,k;
    int s[301], dp[301];
    dp[0]=0;
    
    scanf("%d", &n);

    for (int i=1; i<=n; i++) {
        scanf("%d",&s[i]);
    }
    dp[1]=s[1];
    dp[2]=s[1]+s[2];

    for (int i=3; i<=n; i++) {
        dp[i] = s[i]+ max(dp[i-3]+s[i-1] , dp[i-2]);
    }

    printf("%d",dp[n]);
    return 0;
}