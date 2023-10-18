// 설탕 배달 (실4) 23.7.3
#include <iostream>
using namespace std;
int a,N;
int cnt;

int main() {
    cin>>N;
    a=N;
    while (true) {
        if ( (a%5)==0 ) {
            cnt += a/5;
            break;
        }
        else {
            a-=3;
            cnt+=1;
        }
        if (a<0) {
            cnt = -1;
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}

// 18
// 5 5 5 3
