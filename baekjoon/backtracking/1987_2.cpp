// 백트래킹
// dfs
#include <iostream>
using namespace std;

int Answer, nrow, ncol, map[21][21]; // max map
bool visited[26]; // 'A' to 'Z' (default: false)

// 오른쪽, 아래, 왼쪽, 위쪽 순서로 구현
void dfs(int r, int c, int cnt) {
    Answer = max(cnt, Answer);
    visited[map[r][c]] = true;

    if ( ((c+1) < ncol) && (visited[map[r][c+1]] == false) ) { // 오른쪽
        dfs(r, c+1, cnt+1);
        visited[map[r][c+1]] = false;
    }
    if ( ((r+1) < nrow) && (visited[map[r+1][c]] == false) ) { // 아래쪽
        dfs(r+1, c, cnt+1);
        visited[map[r+1][c]] = false;
    }
    if ( ((c-1) >= 0)   && (visited[map[r][c-1]] == false) ) { // 왼쪽
        dfs(r, c-1, cnt+1);
        visited[map[r][c-1]] = false;
    }
    if ( ((r-1) >= 0)   && (visited[map[r-1][c]] == false) ) { // 위쪽
        dfs(r-1, c, cnt+1);
        visited[map[r-1][c]] = false;
    }
}

void solution() {
    dfs(0,0,1);
    cout << Answer;
}

int main() {

    char ch;

    cin >> nrow >> ncol;
    for ( int i=0; i<nrow; i++ ) {
        for ( int j=0; j<ncol; j++ ) {
            cin >> ch;
            map[i][j] = (int)(ch -'A');
        }
    }

    solution();
}