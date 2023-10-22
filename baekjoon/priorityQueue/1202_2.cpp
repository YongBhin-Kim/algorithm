// 자료구조
// 우선순위 큐 -> 벡터 사용 시 시간 초과
#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <queue>

int main() {

    int n,m,v,k,c;
    vector <pair <int, int> > v1;
    vector <int > v2;
    priority_queue<int > pq;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for ( int i=0; i<n; i++ ) {
        cin >> m >> v;
        v1.push_back(make_pair(m,v));
    }
    for ( int i=0; i<k; i++ ) {
        cin >> c;
        v2.push_back(c);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long price = 0;  int j=0;

    for ( int i=0; i<k; i++ ) {
        for ( ; j<n; j++ ) {
            if ( v2[i] >= v1[j].first ) {
                pq.push(v1[j].second);
            }
            else break;
        }
        if (!pq.empty()) {
            price += (long long)pq.top();
            pq.pop();
        }
    }

    cout << price << endl;


    // for ( int i=0; i<n; i++ ) {
    //     cout << v1[i].first << ", " << v1[i].second << "  ";
    // } cout << "\n";
    // for ( int i=0; i<k; i++ ) {
    //     cout << v2[i] << " ";
    // } cout << "\n";

    return 0;
}
