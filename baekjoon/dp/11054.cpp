// 백준 11054 - 가장긴바이토닉부분수열(g4)

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int n;
int nums[1001];
int dp1[1001], dp2[1001];
int ret;

int main() {
    cin>>n;
    for (int j=0; j<n; j++) {
        dp1[j]=1;
        dp2[j]=1;
        cin>>nums[j];
    }

    for (int j=1; j<n; j++) { // 1 ~ n-1
        // 오름차순
        if (nums[j] > nums[j-1])
            dp1[j] = dp1[j-1]+1;
        if (dp1[j-1] > dp1[j])
            dp1[j] = dp1[j-1];
    }
    for (int j=n-2; j>=0; j--) { // n-1 ~ 1
        // 내림차순
        if (nums[j] > nums[j+1])
            dp2[j] = dp2[j+1]+1;
        if (dp2[j+1] > dp2[j])
            dp2[j] = dp2[j+1];
    }
    ret = max(dp1[n-1], dp2[0]);
    for (int i=0; i<n-2; i++) {
        ret = max(ret, dp1[i] + dp2[i+1]);
    }
    cout << ret;
    return 0;
}