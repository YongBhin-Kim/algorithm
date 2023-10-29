// 정답

#include <iostream>

using namespace std;

int Answer;

int n, a, b, m2, m1, total;

int main(int argc, char** argv)
{
	int T, test_case;

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
        cin>>n>>a>>b;
        total=n;

        m2 = a > b ? a : b; // 큰거
        m1 = a < b ? a : b; // 작은거
        
        while( (total % m1) != 0 ) {
            total = total - m2;
            Answer++;
        }
        Answer += total/m1;
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;
}