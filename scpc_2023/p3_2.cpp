#include <iostream>

using namespace std;

int n, l[10000][10000]; //100000000


int main(int argc, char** argv)
{
	int T, test_case;
    int Answer;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{


		/////////////////////////////////////////////////////////////////////////////////////////////
        cin >> n;
        for (int i=0; i<n; i++) {
            cin >> l[0][i%10000];
        }

        for (int j=1; j<(n%10000); j++) { // j초 뒤 상태는 j-1초 뒤 상태에서 계산.
            for (int i=0; i<(n%10000); i++) {
                // 전에꺼가 있는 경우
                if ( l[j-1][(i+n-1)%n%10000] > 0 ) {
                    // 본인이 있을 땐 유지
                    if ( l[j-1][i] > 0 )
                        l[j][i]=l[j-1][i];
                    else
                        l[j][i]=l[j-1][i]+1;
                }
                else {
                    // 본인이 있을 댄 감소
                    if ( l[j-1][i] > 0 )
                        l[j][i]=l[j-1][i]-1;
                    else
                        l[j][i]=l[j-1][i];
                }
            }
            // 같은 배열들의 개수 찾기
            // for (int i=0; i<n; i++) {
            //     cout << l[j][i] << " ";
            // }
            // cout << endl;
            for (int i=0; i<j; i++) {
                // cout << i << " VS " << j << endl;
                if ( equal(l[i], l[i] + n, l[j]) ) {
                    Answer=j-i;
                    break;
                }
                if (Answer<n) break;
            }
            if (Answer<n) break;
        }


		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}