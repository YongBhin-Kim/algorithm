// 동전2 (골5) v23.7.17

#include <iostream>
#include <algorithm>
using namespace std;

int n, k, cost[101], dp[10001];
int res;

// 입력 :
// 3 15
// 1
// 5
// 12
// 알고리즘 : 
// dp[15] = dp[10]+1 or dp[3]+1 or dp[14]+1
// 출력(dp) :
// 1 2 3 4 1 2 3 4 5 2 3 1 2 3 3 

int main() {
    dp[0]=0;
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>cost[i];
    for (int i=1; i<=k; i++) { // 0 1 .. 15
        res = 10001;
        for (int j=0; j<n; j++)
            if (i>=cost[j])
                res = min(res, dp[i-cost[j]]+1);
        dp[i]=res;
    }
    if (res==10001) cout << -1;
    else cout << res;
    return 0;
}
