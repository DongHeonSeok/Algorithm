/*

VCPP, GPP에서 사용

*/

#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <string.h>
using namespace std;
char d[510][6010];
char t[6000];
int l[510];
int c[510];
void quick(int start, int end, int l[])
{
	int p = l[(start + end) / 2];
	int s = start;
	int e = end;

	while (s <= e) {
		while (l[s] < p && s <= e) s++;
		while (p < l[e] && s <= e) e--;

		if (s <= e) {
			memcpy(t, d[s],sizeof(char) * strlen(d[s]));
			memset(d[s], '\0', sizeof(char)*strlen(d[s]));
			memcpy(d[s], d[e], sizeof(char)*strlen(d[e]));
			memset(d[e], '\0', sizeof(char)*strlen(d[e]));
			memcpy(d[e], t, sizeof(char) * strlen(t));
			memset(t, '\0', sizeof(char) * strlen(t));
			int tmp = l[s];
			l[s] = l[e];
			l[e] = tmp;
			s++; e--;
		}
	}

	if (start < e) quick(start, e, l);
	if (s < end) quick(s, end, l);
}
bool check(char a1[], char a2[])
{
	int len1 = strlen(a1);
	int len2 = strlen(a2);
	int pos = 0;
	bool possible1 = true;
	bool possible2 = true;
	while (pos != len2) {
		if (a1[pos] != a2[pos]) {
			possible1 = false;
			break;
		}
		pos++;
	}
	while (len2 >= 0) {
		if (a1[len1] != a2[len2]) {
			possible2 = false;
			break;
		}
		len1--;
		len2--;
	}
	if (possible1 && possible2)
		return true;
	else
		return false;
	
}
int main()
{
	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<nCount; itr++)
	{
		for (int i = 0; i < 510; i++) {
			memset(d[i], '\0', sizeof(char) * 6000);
		}
		memset(t, '\0', sizeof(char) * 6000);
		for (int i = 0; i < 510; i++) {
			l[i] = c[i] = 0;
		}
		cout << "#testcase" << (itr + 1) << endl;
		int N;
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%s", &d[i]);
			l[i] = strlen(d[i]);
		}
		quick(0, N - 1, l);

		for (int i = 0; i < N; i++) {
			c[i] = 1;
			for (int j = 0; j < i; j++) {
				if (strlen(d[i]) >= strlen(d[j]) && c[j] + 1 > c[i] && check(d[i], d[j])) {
					c[i] = c[j] + 1;
				}
			}
		}
		
		int max = 0;
		for (int i = 0; i<N; i++)
			if (c[i]>max)
				max = c[i];
		printf("%d\n", max);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}