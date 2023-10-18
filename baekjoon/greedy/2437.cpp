// 백준 2437. 저울(골2) 23.06.28

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int weight[1000];

int main() {

    cin>>N;
    for (int i=0; i<N; i++) {
        cin>>weight[i];
    }
    sort(weight, weight+N);

    int res=1;
    for (int i=0; i<N; i++) {
        if ( weight[i]>res ) {
            break;
        }
        res+=weight[i];
    }
    cout << res << endl;

    return 0;
}

// 1 3 --> 2
// 1 2 4 --> 3