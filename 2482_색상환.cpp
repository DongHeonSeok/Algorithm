#include<cstdio>
#define je 1000000003
int nCr[1001][1001];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	nCr[0][0] = 1;
	for (int i = 1; i <= n; i++){
		nCr[i][0] = 1;
		for (int j = 1; j <= i; j++){
			nCr[i][j] = (nCr[i - 1][j - 1] + nCr[i - 1][j]) % je;
		}
	}
	printf("%d\n", (nCr[n - k][k] + nCr[n - k - 1][k - 1]) % je);
	return 0;
}