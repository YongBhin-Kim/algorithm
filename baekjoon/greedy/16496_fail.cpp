// 백준 16496 큰 수 만들기(플5)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int comparator(int a, int b) {
    string as;
    string bs;
    int i,j;
    as = to_string(a);
    bs = to_string(b);
    // 1. Same size
    if (as.size()==bs.size()) {
        return a - b;
    }
    // 2. Different size
    else if (as.size() > bs.size()) {
        for (i=0; i<bs.size(); i++) {
            if (as[i] != bs[i]) return as[i]-bs[i];
        }
        return (stoi(as.substr(i) + bs) - a);
    }
    else {
        for (i=0; i<as.size(); i++) {
            if (as[i] != bs[i]) return bs[i]-as[i];
        }
        return (b - stoi(bs.substr(i) + as ));
    }
}
bool cmp(string a, string b) {
    if (a == b) return false;
    string ab = a + b;
    string ba = b + a;
    if (ab > ba) return true;
    return false;
}

int N;
string nums[1000];
int main() { 
    string a = "3";
    string b = "311";
    cout << (a+b > b+a) << endl;

    return 0;
}