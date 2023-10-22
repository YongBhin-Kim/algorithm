// 최소 힙 기본문제
// S2

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <algorithm>

// 배열에 x를 넣는다. 만일 x가 0이면 배열에서 가장 작은 값을 출력한다.

priority_queue <int, vector<int>, greater<int> > pq;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,x;
    cin >> n;

    for ( int i=0; i<n; i++ ) {
        cin >> x;

        if ( x > 0 ) {
            pq.push(x);
        }
        else if ( x == 0 ) {
            if ( pq.empty() )
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
        }

    }
    return 0;
}