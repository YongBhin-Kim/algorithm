// SCPC 3번(직교 다각형) SOL

#include <stdio.h>

int Answer;
int N, x, y;
int cntx, cnty, flag;
int F[10000][10000];


int main(void)
{
    int T;
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(int test_case = 0; test_case < T; test_case++)
	{
        Answer = 0; cntx=0; cnty=0; flag=0; 
        scanf("%d",&N);
        for(int q=0; q<N; q++) {
            scanf("%d",&x);
            scanf("%d",&y);
            F[x][y]=1;
        }


        for(int i=0; i<=N; i++) {
            printf("SDADSADAS Ansser = %d ", Answer);
            for (int j=0; j<=N; j++) {
                if (F[i][j] == 1) {
                    cnty += 1;
                    if (cnty%2==1){
                        printf("\n[J = %d]", j);
                        Answer -= j;
                    }
                    else {
                        Answer += j;
                    }
                }
                if (F[j][i] == 1) {
                    cntx += 1;
                    if (cntx%2==1) {
                        printf("\n[J = %d]",j);
                        Answer -=j;
                    }
                    else {
                        Answer +=j;
                    }
                }
            }

            printf("\n===================\n");
        /////===========에러 점 처리============///////
            if ((cnty%2==1)  && (flag == 0)) {
                printf("NO\n");
                cnty =0; cntx = 0;
                // 우선 반대로 한줄 복구
                for(int j=1; j<=N; j++) { 
                    if (F[i][j] ==1) {
                        cnty+=1;
                        if (cnty%2==1)
                            Answer += j; // 복구
                        else 
                            Answer -= j; // 복구
                    }
                }
                cnty=0;
                // 재 계산 (3 point 잇기)
                for (int j=1; j<=N; j++) {
                    // 원래 계산 하면서
                    if (F[i][j] ==1) {
                        cnty+=1;
                        if (cnty%2==1)
                            Answer -= j; // 원래계산
                        else
                            Answer += j; // 원래계산
                    }

                    // x축도 홀수인 case//
                    for (int q=0; q<N; q++) { 
                        if (F[q][j] == 1 )
                            cntx +=1;
                    }
                    if (cntx%2==1) {
                        Answer-=j; // 다음거를 더하기 위해..
                        cnty+=1; // 다음꺼 더하게끔 짝수 만들기 ??
                        F[i][j]=0; // 나중에 x는 이 사실을 모름
                    }
                    cntx = 0;
                }
                
                flag=1;
                cntx =0; // 끝내주기
                cnty=0;
            }
            else if ((cntx%2==1)  && (flag == 0)) {
                printf("NO\n");
                cntx =0; cnty = 0;
                for(int j=1; j<=N; j++) { 
                    if (F[j][i] ==1) {
                        cntx+=1;
                        if (cntx%2==1)
                            Answer += j;
                        else
                            Answer -= j; // 복구
                    }
                }
                cntx=0;
                // 재 계산 (3 point 잇기)
                for (int j=1; j<=N; j++) {
                    // 원래 계산 하면서
                    if (F[j][i] ==1) {
                        cntx+=1;
                        if (cntx%2==1)
                            Answer -= j; // 원래계산
                        else
                            Answer += j; // 원래계산
                    }

                    // y축도 홀수인 case//
                    for (int q=0; q<N; q++) { 
                        if (F[j][q] == 1 )
                            cnty +=1;
                    }
                    if (cnty%2==1) { // 3
                        Answer -= j; // 다음거를 더하기 위해.. // -3
                        cntx+=1; // 다음꺼 더하게끔 짝수 만들기 ??
                        F[j][i]=0; // 나중에 x는 이 사실을 모름
                    }
                    cnty = 0;
                }
                flag=1;
                cnty =0; // 끝내주기
                cntx = 0;
            }
        }


        printf("Case #%d\n", test_case+1);
        printf("%d\n", Answer);
    }

	return 0;//Your program should return 0 on normal termination.
}