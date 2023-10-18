#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <vector <int> > t2;

int s,e;

int n;

int main() {

    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> s >> e;

        vector <int> es;

        es.push_back(e); es.push_back(s);

        t2.push_back(es);
    }

    sort(t2.begin(), t2.end());

    int res = 0, end; // vector[i] = e, s 

    end = t2[0][0]; res++;

    for ( int i=1; i<n; i++ ) {
        if ( t2[i][1] >= end ) {
            end = t2[i][0];
            res ++;
        }
    }

    // for (int i=0; i<n; i++)
    //     cout << t2[i][0] << " " << t2[i][1] << '\n';

    cout << res;

    return 0;
}

// 5
// 1 2
// 5 5
// 5 5
// 5 5
// 3 5