// 포도주 시식
// 6, 10, 13, 9, 8, 1
// 6, 16, 23, 
#include <stdio.h>

int max(int a, int b) {
    return (a>b) ? a:b;
}

int main() {

    int n, ans=0;
    int num[10000], dp[10000];
    scanf("%d",&n);
    for(int i=0; i<n; i++) {
        scanf("%d",&num[i]);        
    }
    dp[0]=num[0];
    dp[1]=num[0]+num[1];
    dp[2]=max(max(dp[1], num[0]+num[2]), num[1]+num[2]);
    // ans=max(dp[1], dp[2]);
    for (int i=3; i<n; i++) {
        dp[i]=max(max(dp[i-1], num[i]+num[i-1]+dp[i-3]), dp[i-2]+num[i]);
        // if(dp[i]>ans){
        //     ans=dp[i];
        // }
    }
    printf("%d\n",dp[n-1]);
    // printf("%d\n",ans);

    return 0;
}