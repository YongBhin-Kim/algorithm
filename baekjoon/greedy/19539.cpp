// 백준 19539 : 사과나무(골5) 23.07.10

#include <iostream>
using namespace std;

int n; // 사과나무의 개수
int h; // 사과나무의 높이
int day, two, sum; // 걸리는 일수, 2짜리의 개수, 높이의 합

// 2의 개수가 1의 개수보다 많아야함

int main() {

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> h;
        two += (h/2);
        sum += h;
    }
    if ((sum%3)!=0) cout << "NO" << endl;
    else {
        day = sum/3;
        if (two >= day) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}