/*

VCPP, GPP에서 사용

*/
#include <cstdio>

#include <iostream>
using namespace std;

long long A[1001000];
void init(int N)
{
	for (int i = 0; i < N; i++)
		A[i] = 0;

}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int N;
		scanf("%d", &N);
		
		for (int i = 0; i < N; i++) {
			scanf("%lld", &A[i]);
		}
		long long val = A[N - 1];
		long long cnt = 0LL;
		long long sum = 0LL;
		long long ans = 0LL;
		for (int i = N - 2; i >= 0; i--) {
			if (A[i] <= val) {
				sum += A[i];
				cnt++;
			}
			else if (A[i]>val) {
				ans += (val*cnt) - sum;
				val = A[i];
				cnt = 0LL;
				sum = 0LL;
			}
		}
		if (cnt != 0) {
			ans += (val*cnt) - sum;
		}
		printf("%lld\n", ans);
		init(N);
		
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}