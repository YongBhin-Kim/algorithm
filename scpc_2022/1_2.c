#include <stdio.h>

int Answer = 0;

int main(void)
{
    int T, test_case;
    int N;
    int P[10], V[10];

    setbuf(stdout, NULL);

    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++) {
        Answer = 0;
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            scanf("%d", &P[i]); }
        for (int i=0; i<N; i++) {
            scanf("%d", &V[i]); }

        printf("Case #%d\n", test_case+1);
        int i=0, j = 0, temp = 0, tmp = 0; 
        int flag = 1;

        for (i = 0; i < N - 1 && flag == 1; i++) {
            flag = 0;
            for (j = 0; j < N - (i + 1); j++) {
                if (V[j] > V[j + 1]) {
                    Answer+= (P[j+1]-P[j]);
                    temp = V[j + 1];
                    V[j + 1] = V[j];
                    V[j] = temp;
                    flag = 1;
                    tmp = 0;
                    for (int k=j+1; k<N - (i + 1); k++) {
                        if (V[j]>V[k]) {
                            tmp = 1;
                        }
                    }
                    if (tmp == 1){
                        Answer-=(P[j+1]-P[j]);
                    }
                }
            }
        }
        // bubble sort 출처 https://blog.naver.com/bogleboglegamjatang/222777793006
        Answer = Answer * 2;
        printf("%d\n", Answer);
    }

    return 0;
}