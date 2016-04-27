#include <cstdio>
using namespace std;

int d[101][10001];
int c[101];
int v[101];
int main()
{
	int T, N;
	scanf("%d %d", &T, &N);
	d[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		d[i][0] = 1;
		scanf("%d %d", &c[i], &v[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			for (int k = 0; k <= v[i]; k++) {
				if (c[i] * k > j)
					break;
				d[i][j] += d[i - 1][j - c[i] * k];
			}
		}
	}
	printf("%d\n", d[N][T]);
	return 0;
} 