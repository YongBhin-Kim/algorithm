// 백준 15486 - 퇴사(g5)
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int dp[1500001];
int n;
int t,p;
int main() {
    cin>>n;
    for (int d=1; d<=n; d++) {
        cin >> t >> p;
        dp[d+t-1] = max(dp[d+t-1], dp[d-1] + p);
        dp[d] = max(dp[d-1], dp[d]);
    }
    cout << dp[n];
    return 0;
}