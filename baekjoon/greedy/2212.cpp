// 2212(골5) 센서 23.7.4
#include <iostream>
#include <algorithm>
using namespace std;

int d[9999];
int sensor[10000];
int N, K, res;

int main() {
    cin>>N>>K;
    for (int i=0; i<N; i++)
        cin>>sensor[i];
    sort(sensor, sensor+N);
    for (int i=0; i<N-1; i++)
        d[i] = sensor[i+1]-sensor[i];
    sort(d, d+(N-1));
    for (int i=0; i<N-K; i++)
        res+=d[i];
    cout << res << endl;

    return 0;
}

// 굿노트 코테
// [1 3] [6 6 7 9]
// 2 3 1 2 -> [1 2] 2 3

// [3 6] [7 8] [10 12] [14 15] [18 20]
// 3 1 1 2 2 2 1 3 2 -> [1 1 1 2 2] 2 2 3 3
// 31212