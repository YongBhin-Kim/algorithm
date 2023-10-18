// 백준 16496 : 큰 수 만들기(플5) 23.07.06
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comparator(const string &a, const string &b) {
    return a + b > b + a;
}

int N;
bool iszero;
string nums[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    bool iszero = true;

    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> nums[i];
        if (nums[i]!="0") iszero=false;
    }

    if (iszero==true) cout << 0;
    else {
        sort(nums, nums+N, comparator);
        
        for (int i=0; i<N; i++)
            cout << nums[i];
    }

    return 0;
}