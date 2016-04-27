#include <iostream>
#include <cstdio>

using namespace std;

long long memo[110][110][110];
long long mod = 1000000007;
int main()
{
	int N, L, R;

	scanf("%d %d %d", &N, &L, &R);

	memo[1][1][1] = 1;

	for(int i=2; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			for(int k=1; k<=N; k++) {
				memo[i][j][k] = (memo[i-1][j-1][k] + memo[i-1][j][k-1] + (memo[i-1][j][k] * (i-2)))%mod;
			}
		}
	}
	
	printf("%d\n", memo[N][L][R]);
	return 0;
}