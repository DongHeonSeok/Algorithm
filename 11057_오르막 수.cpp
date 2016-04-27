#include <cstdio>
#define MAX 1001

long long dp[MAX][10] = { 1 };
long long mod = 10007;

int main(int argc, const char * argv[]) {

	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 10; j++){
			for (int k = 0; k <= j; k++){
				dp[i][j] += dp[i - 1][k];
				dp[i][j] %= mod;
			}
		}
	}

	long long total = 0;

	for (int i = 0; i < 10; i++)
		total += dp[n][i];
	total %= mod;
	printf("%lld", total);
	return 0;
}