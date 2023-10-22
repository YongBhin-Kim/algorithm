// boj11000
// 우선순위 큐
// 그리디
// 정렬

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

priority_queue <int, vector<int>, greater<int> > pq;
vector < pair <int, int> > se;

int main() {

    int n, s, e;
    cin >> n;

    for ( int i=0; i<n; i++ ) {
        cin >> s >> e;
        se.push_back(make_pair(s,e));
    }

    sort(se.begin(), se.end());

    pq.push(se[0].second);
    for ( int i=1; i<n; i++ ) {
        if ( se[i].first >= pq.top() ) {
            pq.pop();
            pq.push(se[i].second);
        }
        else {
            pq.push(se[i].second);
        }
    }
    cout << pq.size() << endl;

    return 0;
}