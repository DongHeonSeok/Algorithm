#include <cstdio>
using namespace std;
char a[1010];
char b[1010];
int d[1010][1010];
int p[1010][1010];
char c[1010];
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
	int idx = 0;
	bool flag = false;
	
	for (int i = 1; i <= alen; i++) {
		flag = false;
		for (int j = 1; j <= blen; j++) {
			if (a[i - 1] == b[j - 1]) {
				d[i][j] = d[i - 1][j - 1] + 1;
				p[i][j] = 1;
			}
			else {
				if (d[i - 1][j] > d[i][j - 1]) {
					d[i][j] = d[i - 1][j];
					p[i][j] = 2;
				}
				else {
					d[i][j] = d[i][j - 1];
					p[i][j] = 3;
				}
			}
		}
	}
	printf("%d\n", d[alen][blen]);
	while (alen>0 && blen>0){
		switch (p[alen][blen]){
		case 1:
			c[idx] += a[alen - 1];
			idx++;
			alen--;
			blen--;
			break;
		case 2:
			alen--;
			break;
		case 3:
			blen--;
			break;
		}
	}
	for (int i = idx - 1; i >= 0; i--) {
		printf("%c", c[i]);
	}

	return 0;
}