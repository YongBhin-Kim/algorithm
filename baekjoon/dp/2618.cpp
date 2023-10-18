// 백준 2618 - 경찰차(p4)

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 1001
int n;
int w;
int s[MAX][2];
int c1[2], c2[2];
int map[MAX][MAX];

// 1 1 / 3 5 --> 6
// 6 6 / 3 5 --> 4
int distance(int now[2], int s[2]) {
    return abs(s[0]-now[0]) + abs(s[1]-now[1]);
}

int main() {
    cin>>n;
    cin>>w;
    c1[0]=c1[1]=1;
    c2[0]=c2[1]=n;
    for (int i=0; i<w; i++) {
        cin >> s[i][0] >> s[i][1];
    }
    for (int i=0; i<w; i++) {
        if (distance(c1, s[i]) < distance(c2, s[i])) {
            c1[0] = s[i][0];
            c1[1] = s[i][1];
        }
        else {
            
        }
    }

    return 0;
}