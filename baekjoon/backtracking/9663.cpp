#include <iostream>
using namespace std;


#define MAX 15
int N;
int col[MAX];
int RES;

bool check(int row) {
    for (int i=0; i<row; i++) {
        if (col[row]==col[i] || abs(col[row]-col[i])==abs(row-i)) return false;
    }
    return true;
}

void nqueen(int row) {

    if (row==N) RES++;

    for (int c=0; c<N; c++) {
        col[row]=c;
        if (check(row)) nqueen(row+1);
    }
}

int main() {
    cin >> N;
    nqueen(0);
    cout << RES << endl;
    return 0;
}

// o o o o // 0 : 0 1 x
// o o - - // 2 : 1 3 x
// o - o - // 
// o - - o

// 