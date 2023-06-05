//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            else if ((cntx%2==1)  && (flag == 0)) {
                printf("\ncntx = %d\n",cntx);
                cntx =0; cnty = 0;
                // 우선 반대로 한줄 복구
                for(int j=1; j<=N; j++) { 
                    if (F[j][i] ==1) {
                        cntx+=1;
                        if (cntx%2==1){
                            Answer += j; // 복구
                            // Answer -= j; // 원래계산
                        }
                        else {
                            Answer -= j; // 복구
                            // Answer += j; // 원래계산
                        }
                    }
                }
                printf("[복구완료] %d\n", Answer);
                cntx=0;
                // 재 계산 (3 point 잇기)
                for (int j=1; j<=N; j++) {
                    // 원래 계산 하면서
                    printf("Answe1r = %d\n", Answer);
                    if (F[j][i] ==1) {
                        cntx+=1;
                        if (cntx%2==1){
                            Answer -= j; // 원래계산
                        }
                        else {
                            Answer += j; // 원래계산
                        }
                    }
                    // y축도 홀수인 case//
                    for (int m=0; m<N; m++) { 
                        if (F[j][m] == 1 ) {
                            cnty +=1;
                        }
                    }
                    if (cnty%2==1) { // 3
                        Answer -= j; // 다음거를 더하기 위해.. // -3
                        cntx+=1; // 다음꺼 더하게끔 짝수 만들기 ??
                        F[j][i]=0; // 나중에 x는 이 사실을 모름
                    }
                    cnty = 0;
                }
                printf("from y (3point), ans = %d\n", Answer);
                flag=1;
                cnty =0; // 끝내주기
            }
