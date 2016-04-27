#include <cstdio>
using namespace std;
long long d[210][210];
const long long mod = 1000000000;
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	d[0][0] = 1LL;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int l = 0; l <= j; l++) {
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= mod;
			}
		}
	}
	printf("%lld\n", d[K][N]);
	return 0;
}