// 부분점수 (40점)

#include <iostream>
#include <algorithm>

using namespace std;

int Answer;
int n, d, st[1100000];

int main(int argc, char** argv)
{
	int T, test_case;
    int st1, st2;
    unsigned int d1, d2;

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin >> n >> d;
        for (int i=0; i<n; i++)
            cin >> st[i];

        sort(st, st+n);

        // n = 2
        for (int k=0; k<n; k++) {  // k = 0 1
            for (int i=0; i+k<n; i++) { // (i = 0 1) (i = 0)
                if ( ((st[i]>0) && (st[i+k]<0)) || ((st[i]<0) && (st[i+k]>0)) ) {
                    st1 = abs(st[i]);
                    st2 = abs(st[i+k]);
                    d1 = 2*min(st1, st2);
                    d2 = max(st1, st2);

                    if ( (d1 + d2) > 1000000000 )
                        break;

                    if ( d >= (d1 + d2) ) {
                        Answer = max(Answer, k+1);
                        break;
                    }
                }
                else {
                    if ( d >= max(abs(st[i]), abs(st[i+k])) ) {
                        Answer = max(Answer, k+1);
                        break;
                    }
                }
                
            }
        }


		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}