// 절댓값 힙 기본문제
#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>

// 절대값이 작은거, 같다면 작은 수


struct compare {
    bool operator()(int a, int b) {
        if ( abs(a) == abs(b) ) {
            return a > b; 
        }
        return abs(a) > abs(b);
    }
};

priority_queue <int, vector<int>, compare > pq;

int main() {
    int n,x;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for ( int i=0; i<n; i++ ) {
        cin >> x;
        if ( x == 0 ) {
            if ( pq.empty() ) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else {
            pq.push(x);
        }
    }
    return 0;
}
