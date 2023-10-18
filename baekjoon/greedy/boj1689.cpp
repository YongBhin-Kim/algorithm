// boj1689
// 겹치는 선분
// G3
// 그리디
// 정렬
// 스위핑

#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

pair <int, int> se[2000001];

int main() {

    int n;
    int s,e;
    int cnt; // 선분의 개수
    int res; // 선분의 최대 개수 (결과값)

    res = cnt = 0;
    cin >> n;
    for ( int i=0; i<n; i++ ) {
        cin >> s >> e;
        se[i] = make_pair(s, 1);
        se[i+n] = make_pair(e, -1);
    }
    sort(se, se + (2*n));

    for ( int i=0; i<2*n; i++ ) {
        cnt += se[i].second;
        res = max(cnt, res);
    }
    cout << res << endl;

    return 0;
}