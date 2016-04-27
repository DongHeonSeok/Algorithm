/*

VCPP, GPP에서 사용

*/
#include <cstdio>
#include <iostream>
using namespace std;
char A[110];
char B[110];
char C[110];
void init()
{
	for (int i = 0; i < 110; i++) {
		A[i] = B[i] = C[i] = '\0';
	}
}
int len(char X[])
{
	int ret = 0;
	for (ret = 0; X[ret] != '\0'; ret++);
	return ret;
}
void cpy(char X[], char Y[], int x, int y)
{
	char tmp[110];
	for (int i = 0; i < x; i++) {
		tmp[i] = X[i];
		X[i] = '\0';
	}
	for (int i = 0; i < y; i++) {
		X[i] = Y[i];
		Y[i] = '\0';
	}
	for (int i = 0; i < x; i++) {
		Y[i] = tmp[i];
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;
		int a = 0, b = 0;
		char c = '0';
		scanf("%s", A);
		scanf("%s", B);

		a = len(A);
		b = len(B);

		if (a < b) {
			cpy(A, B, a, b);
			int tmp = a;
			a = b;
			b = tmp;
		}
		char tmp = '0';
		int len = a, idx = a, x = 0, y = 0, z = 0;
		a--, b--;
		while (1) {
			if (b < 0) {
				for (int i = a; i >= 0; i--) {
					x = A[i] - '0';
					y = tmp - '0';
					z = x + y;
					if (z != 0) {
						C[idx] = (z % 10) + '0';
						tmp = (z / 10) + '0';
					}
					else
						C[idx] = A[i];
					idx--;
				}
				C[idx] = tmp;
				break;
			}
			x = A[a] - '0';
			y = B[b] - '0';
			z = x + y + (tmp - '0');
			if (z != 0) {
				C[idx] = (z % 10) + '0';
				tmp = (z / 10) + '0';
			}
			else 
				C[idx] = A[a];
			a--, b--, idx--;
		}

		for (int i = 0; i <= len; i++) {
			if (i==0 && C[0] == '0') continue;
			printf("%c", C[i]);
		}
		printf("\n");
		init();
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}