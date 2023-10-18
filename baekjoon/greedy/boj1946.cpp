// 그리디,정렬

#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

int t,n;

vector < pair<int, int> > score12;
int s1, s2;

int solve() {

    int cnt = 1;
    sort(score12.begin(), score12.end());

    // O(nlogn)
    vector<int> score2;
    for (int i=0; i<n; i++) {
        score2.push_back(score12[i].second);
    }

    int min = score2[0];
    int prev = 0;
    // 나보다 작은게 나오면 안됨
    for (int i=1; i<n; i++) {
        // 시간초과
        // int min = *min_element(score2.begin(), score2.begin() + i);
        // if ( min > score2[i] )
        //     cnt++;

        // 통과
        // if ( min > score2[i-1] ) {
        //     min = score2[i-1];
        // }
        // if ( min > score2[i] )
        //     cnt++;

        // 개선
        if ( score2[prev] > score2[i] ) {
            cnt++;  
            prev = i;
        }
    }

    return cnt;
}
int main () {
    int cnt;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> s1 >> s2;
            score12.push_back(make_pair(s1, s2));
        }
        cnt = solve();
        cout << cnt << '\n';
        score12.clear();
    }

    return 0;
}

// 2
// 5
// 3 2
// 1 4
// 4 1
// 2 3
// 5 5
// 7
// 3 6
// 7 3
// 4 2
// 1 4
// 5 7
// 2 5
// 6 1