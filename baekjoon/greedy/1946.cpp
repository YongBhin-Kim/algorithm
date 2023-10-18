// 백준 1946 : 큰 수 만들기(실1) 23.07.10

#include <iostream>
using namespace std;


int t, n;
int s[100001];
int val;
int res;


int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        res=1;
        while(n--) {
            cin>>val;
            cin>>s[val]; // s[][]
        }
        for (int i=0; i<n-1; i++) {
            if (s[i]>s[i+1])
                res++;
        }
        cout << res << endl;

    }
    return 0;
}
