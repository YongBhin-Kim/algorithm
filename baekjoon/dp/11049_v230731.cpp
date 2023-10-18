// 행렬 곱셈 순서(dp) G3 v230731

#include <iostream>
#include <algorithm>
using namespace std;

// 경우의수 O((n-1)!)
// dp 이용 --> O(n^3)

/*
dp[i][j] : i부터 j까지 곱셈의 횟수의 최소
*/

int mat[500][2];  // (row,col) 1KB
int dp[500][500]; // (i, j)    250KB

int main() {

    int n;

    cin>>n;
    for (int i=0; i<n; i++) {
        cin >> mat[i][0] >> mat[i][1]; // mat[인덱스][행수,열수]
    }

    for (int i=1; i<n; i++) { // 칸의 개수
        for (int j=0; j+i<n; j++) { // 시작 위치
            dp[j][j+i] = __INT_MAX__; // 초기화
            for (int k=0; k<i; k++) { // 칸 분할 개수
                dp[j][j+i] = min( dp[j][j+i], dp[j][j+k] + dp[j+k+1][j+i] + mat[j][0]*mat[j+k][1]*mat[j+i][1] );
            }
        }
    }

    cout << dp[0][n-1] << endl;


    return 0;
}