#include <stdio.h>

int main() {
    int l, p, num[6];
    scanf("%d %d", &l, &p);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num[i]);
        printf("%d ", num[i] - l*p);
    }
    num - l * p;


    // -----
    int testArr[10];
    for (int i = 0; i < 9; i++) {
        scanf("%d", &testArr[i]);
    }
    for (int i = 0; i < sizeof(testArr); i++) {
        printf("%d ", testArr[i]);
    }

    return 0;
}