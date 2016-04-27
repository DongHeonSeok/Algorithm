/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>
using namespace std;
int a[110];
int d[11000];
void init()
{
	for (int i = 0; i < 110; i++) {
		a[i] = 0;
	}
	for (int i = 0; i < 11000; i++) {
		d[i] = 0;
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		cout << "#testcase" << (itr + 1) << endl;
		int N, sum = 0, ans = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		d[0] = 1;
		int total = 0;
		int step = 2;
		for (int i = 0; i < N; i++) {
			int val = a[i];
			for (int j = 0; j <= sum; j++) {
				if (d[j] != step && d[j] != 0) {
					if (d[j + a[i]] == 0) {
						d[j + a[i]] = step;
					}
					if (j + a[i] > total)
						total = j + a[i];
				}
			}
			step++;
			sum = total;
		}
		for (int i = 0; i <= total; i++) {
			if (d[i] !=0)
				ans++;
		}
		printf("%d\n", ans);
		init();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}