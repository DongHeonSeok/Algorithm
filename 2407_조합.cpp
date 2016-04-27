#include <cstdio>
using namespace std;
unsigned long long d[200][200];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	d[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		d[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}
	printf("%llu\n", d[n][m]);
	return 0;
}