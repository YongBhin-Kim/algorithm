// boj1461
// 도서관
// G4
// 그리디
// 정렬

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool cmp(int a, int b) {
    return a > b;
}

int main() {

    int n, m, x;
    vector <int> minus, plus;

    // 입력
    cin >> n >> m;
    for ( int i=0; i<n; i++ ) {
        cin >> x;
        if ( x < 0 )
            minus.push_back(x*(-1));
        else
            plus.push_back(x);
    }

    sort(minus.begin(), minus.end(), cmp);
    sort(plus.begin(), plus.end(), cmp);

    int distance = 0;
    if ( (minus.size() > 0) && (plus.size() > 0) )
        distance -= max( minus[0], plus[0] );
    else if ( minus.size() > 0 )
        distance -= minus[0];
    else 
        distance -= plus[0];

    // 마이너스 큰놈들 털기
    int minus_size = minus.size();
    for ( int i=0; i<minus_size/m; i++ ) {
        distance += minus[0]*2;
        for ( int j=0; j<m; j++ ) {
            minus.erase(minus.begin());
        }
    }
    // 남은거 털기
    if ( minus.size() > 0 )
        distance += minus[0]*2;

    // 플러스 큰놈들 털기
    int plus_size = plus.size();
    for ( int i=0; i<plus_size/m; i++ ) {
        distance += plus[0]*2;
        for ( int j=0; j<m; j++ ) {
            plus.erase(plus.begin());
        }
    }
    // 남은거 털기
    if ( plus.size() > 0 )
        distance += plus[0]*2;

    cout << distance << endl;

    return 0;
}