// 백트래킹
// dfs

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


int map[21][21];
int row, col, res; // input row, col, result
bool visited[26];
// direction = 1(right), 2(down), 3(left), 4(up)


void dfs(int r, int c, int cnt) {
    visited[map[r][c]] = true;
    res = max(cnt, res);
    cout << r << "행 " << c << "열 방문\n";

    // 오른쪽
    if ( ((c+1) < col) && (visited[map[r][c+1]] == false) ) {
        dfs(r,c+1,cnt+1);
        visited[map[r][c+1]]=false;
    }
    // 아래
    if ( ((r+1) < row) && (visited[map[r+1][c]] == false) ) {
        dfs(r+1,c,cnt+1);
        visited[map[r+1][c]]=false;
    }
    // 왼쪽
    if ( ((c-1) >= 0)  && (visited[map[r][c-1]] == false) ) {
        dfs(r,c-1,cnt+1);
        visited[map[r][c-1]]=false;
    }
    // 위쪽
    if ( ((r-1) >= 0)  && (visited[map[r-1][c]] == false) ) {
        dfs(r-1,c,cnt+1);
        visited[map[r-1][c]]=false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    char ch;

    cin >> row >> col;
    for ( int i=0; i<row; i++ ) {
        for ( int j=0; j<col; j++ ) {
            cin >> ch;
            map[i][j] = (int)(ch-'A');
        }
    }
    dfs(0,0,1);

    cout << res << endl;


    return 0;
}
