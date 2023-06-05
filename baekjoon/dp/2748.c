// 피보나치

#include <stdio.h>

// int fibo(int n) {
//     if (n==0) {return 0;}
//     else if (n==1) {return 1;}
//     else {return fibo(n-1) + fibo(n-2);}
// }


long long int ans[91];
long long int fibo_dp(int n) {
    ans[0] = 0;
    ans[1] = 1;
    if (n>1) {
        for (int i=2; i<=n; i++) {
            ans[i] = ans[i-1] + ans[i-2];
        }
    }
    return ans[n];
}


int main() {

    int n;
    scanf("%d", &n);
    printf("%lld\n", fibo_dp(n));

    return 0;
}