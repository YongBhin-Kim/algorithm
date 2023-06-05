// 연속합
#include <stdio.h>
int max(int a, int b) {

    return (a>b) ? a:b;
}
int main() {
    int n, ans=0;
    int num[100001], dp[100001];
    scanf("%d",&n);

    for (int i=0; i<n; i++) {
        scanf("%d",&num[i]);
    }
    dp[0]=num[0];

    for (int i=1; i<n; i++) {
        dp[i] = max(dp[i-1]+num[i], num[i]);
        if (ans<max(dp[i], dp[i-1])) {
            ans=max(dp[i], dp[i-1]);
        }
    }
    printf("%d\n",ans);
    return 0;
}