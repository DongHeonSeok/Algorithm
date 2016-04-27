/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>
using namespace std;
long long a[100100];
void init()
{
	for (int i = 0; i < 100100; i++) {
		a[i] = 0LL;
	}
}
void quick(int start, int end, long long x[])
{
	long long p = x[(start + end) / 2];
	long long s = start;
	long long e = end;

	while (s <= e) {
		while (x[s] > p && s <= e) s++;
		while (p > x[e] && s <= e) e--;
		if (s <= e) {
			int tmp = x[s];
			x[s] = x[e];
			x[e] = tmp;
			s++, e--;
		}
	}
	if (start < e) quick(start, e, x);
	if (s < end) quick(s, end, x);
}

int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int N;
		long long sum = 0LL;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
		}
		quick(0, N - 1, a);
		int idx = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			idx++;
			if (idx == 3) {
				sum -= a[i];
				idx = 0;
				cnt++;
			}
		}
		
		printf("%lld\n", sum);
	
		init();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}