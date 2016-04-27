/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
char a[50];
char b[50];
long long x[1000];
long long y[1000];
int xidx = 0;
int yidx = 0;
void init()
{
	for (int i = 0; i < 50; i++) {
		a[i] = b[i] = '\0';
	}
}
int LEN(char x[])
{
	int pos = 0, ret = 0;
	while (x[pos] != '\0') {
		pos++;
		ret++;
	}
	return ret;
}
void CMP(char z[], int len, int type)
{
	long long val = 0LL;
	if (type == 2) {
		for (int i = 0; i < len; i++) {
			if (z[i] == '0') z[i] =  '1';
			else z[i] = '0';
			for (int j = 0; j < len; j++) {
				val += (z[j] - '0') * (long long)pow((double)2, len - j - 1);
				
			}
			x[xidx] = val;
			xidx++;
			if (z[i] == '0') z[i] = '1';
			else z[i] = '0';
			val = 0LL;
		}
	}
	else {
		for (int i = 0; i < len; i++) {
			if (z[i] == '0') {
				z[i] = '1';
				for (int j = 0; j < len; j++) {
					val += (z[j] - '0') * (long long)pow((double)3, len - j - 1);
				}
				y[yidx] = val;
				yidx++;
				val = 0LL;
				z[i] = '2';
				for (int j = 0; j < len; j++) {
					val += (z[j] - '0') * (long long)pow((double)3, len - j - 1);
				}
				y[yidx] = val;
				yidx++;
				val = 0LL;
				z[i] = '0';
			}
			if (z[i] == '1') {
				z[i] = '2';
				for (int j = 0; j < len; j++) {
					val += (z[j] - '0') * (long long)pow((double)3, len - j - 1);
				}
				y[yidx] = val;
				yidx++;
				val = 0LL;
				z[i] = '0';
				for (int j = 0; j < len; j++) {
					val += (z[j] - '0') * (long long)pow((double)3, len - j - 1);
				}
				y[yidx] = val;
				yidx++;
				val = 0LL;
				z[i] = '1';
			}
			if (z[i] == '2') {
				z[i] = '1';
				for (int j = 0; j < len; j++) {
					val += (z[j] - '0') * (long long)pow((double)3, len - j - 1);
				}
				y[yidx] = val;
				yidx++;
				val = 0LL;
				z[i] = '0';
				for (int j = 0; j < len; j++) {
					val += (z[j] - '0') * (long long)pow((double)3, len - j - 1);
				}
				y[yidx] = val;
				yidx++;
				val = 0LL;
				z[i] = '2';
			}
		}
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		scanf("%s", a);
		scanf("%s", b);
		int alen = LEN(a);
		int blen = LEN(b);

		CMP(a, alen, 2);
		CMP(b, blen, 3);
		long long ans = 0LL;
		for (int i = 0; i < xidx; i++) {
			for (int j = 0; j < yidx; j++) {
				if (x[i] == y[j]) {
					ans = x[i];
					break;
				}
			}
		}
		printf("%lld\n", ans);
		init();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}