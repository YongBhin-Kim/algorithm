// 최대 힙 기본문제
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <queue>

priority_queue<int, vector<int>, less<int> > pq;

int main() {

    int n,x;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> n;
    while(n--) {
        cin >> x;
        if ( x ) {
            pq.push(x);
        }
        else {
            if ( pq.empty() ) {
                cout << 0 << '\n';
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }

    }


    return 0;
}