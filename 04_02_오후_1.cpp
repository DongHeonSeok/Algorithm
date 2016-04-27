/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>
using namespace std;
char s[60];
char o[60];
void init()
{
	for (int i = 0; i < 60; i++) {
		s[i] = '\0';
		o[i] = '0';
	}
}
int L(char a[])
{
	int ret = 0;
	int pos = 0;
	while (a[pos] != '\0') {
		ret++;
		pos++;
	}
	return ret;
}
void F(char a[], int idx, int len, char c)
{
	for (int i = idx; i < len; i++) {
		a[i] = c;
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		init();
		cout << "#testcase" << (itr + 1) << endl;
		scanf("%s", s);

		int len = L(s);
		int ans = 0;
		for (int i = 0; i < len; i++) {
			if (s[i] != o[i]) {
				ans++;
				F(o, i, len, s[i]);
			}
		}

		printf("%d\n", ans);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}