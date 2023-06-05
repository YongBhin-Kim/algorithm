// SCPC 1번(개미) SOL

#include <stdio.h>

int Answer = 0;
int T, test_case;
int N, left, right, pivot, temp;
int P[1001], V[1001];

void quickSort(int V[], int L, int R, int P[]) {
    left = L, right = R;
    pivot = V[(L + R) / 2];
    do
    {
        while (V[left] < pivot)
            left++;
        while (V[right] > pivot)
            right--;
        if (left<= right)
        {
            if (V[left]!=V[right]) {
                Answer += (P[right]-P[left]);
                temp = V[left];
                V[left] = V[right];
                V[right] = temp;
            }
            left++;
            right--;
        }
    } while (left<= right);

    if (L < right)
        quickSort(V, L, right,P);

    if (left < R)
        quickSort(V, left, R,P);
    
}


int main(void)
{
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for(test_case = 0; test_case < T; test_case++)
    {
        Answer = 0;
        scanf("%d", &N);
        for (int i=0; i<N; i++) {
            scanf("%d", &P[i]);
        }
        for (int i=0; i<N; i++) {
            scanf("%d", &V[i]);
        }
        printf("Case #%d\n", test_case+1);
        quickSort(V,0,N-1,P);
        printf("%d\n", Answer*2);
    }

    return 0;//Your program should return 0 on normal termination.
}