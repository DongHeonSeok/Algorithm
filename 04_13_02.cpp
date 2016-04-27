/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int A[11];
int D[11][2];
void init1()
{
	for (int i = 0; i < 11; i++) {
		A[i] = D[i][0] = D[i][1] = 0;
	}
}
void init2()
{
	for (int i = 0; i < 11; i++) {
		D[i][0] = D[i][1] = 0;
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{
		
		cout << "#testcase" << (itr + 1) << endl;
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) 
			scanf("%d", &A[i]);
		int ans = 0;
		int idx = 0;
		do
		{
			D[0][1] = A[0]; //1=left 0 = right
			for (int i = 1; i < N; i++) {
				if (A[i] <=D[i - 1][1]) {
					ans += 2;
					D[i][0] = D[i-1][0] + A[i];
					D[i][1] = D[i - 1][1] + A[i];
					idx++;
				}
				else {
					D[i][0] = D[i - 1][0] + A[i];
					D[i][1] = D[i - 1][1] + A[i];
				}
			}
			/*if (D[N - idx - 1][1] < D[N - 1][0])
				ans--;*/
			init2();
			
		} while (next_permutation(A, A+N));
		int ac = 1;
		printf("%d\n", ans);
		init1();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}