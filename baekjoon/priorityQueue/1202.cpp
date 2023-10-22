// 자료구조
// 우선순위 큐 -> 벡터 사용 시 시간 초과

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n,k,m,v,c;

// typedef struct cmp {
//     bool operator() (int a, int b){
//         return a > b;
//     }
// };

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {

    vector <pair<int, int> > pv; // v, m
    vector <int> vc; // c

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    for ( int i=0; i<n; i++ ) {
        cin >> m >> v;
        pv.push_back(make_pair(v,m));
    }
    for ( int i=0; i<k; i++ ) {
        cin >> c;
        vc.push_back(c);
    }

    sort(pv.begin(), pv.end(), cmp);
    sort(vc.begin(), vc.end());
    int price = 0;

    // vc를 돌면서
    for ( int j=0; j<k; j++ ) {
        // pv를 돌면서
        for ( int i=0; i<pv.size(); i++ ) {
            if ( vc[0] >= pv[i].second ) {
                price += pv[i].first;
                pv.erase(pv.begin() + i); // i번째 원소 삭제
                vc.erase(vc.begin());
                break;
            }
        }
    }
    cout << price << endl;

    return 0;
}