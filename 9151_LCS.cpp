#include <cstdio>
using namespace std;
char a[1010];
char b[1010];
int d[1010][1010];
int LEN(char x[])
{
	int ret = 0;
	int pos = 0;
	while (x[pos] != '\0') {
		ret++;
		pos++;
	}
	return ret;
}
int main()
{
	scanf("%s", a);
	scanf("%s", b);

	int alen = LEN(a);
	int blen = LEN(b);

	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			if (a[i - 1] == b[j - 1])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = d[i - 1][j] > d[i][j - 1] ? d[i - 1][j] : d[i][j - 1];
		}
	}
	printf("%d\n", d[alen][blen]);

	return 0;
}