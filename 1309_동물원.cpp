#include <cstdio>
using namespace std;
int D[100100];
int main()
{
	int mod = 9901;
	int N;
	scanf("%d", &N);
	D[0] = 1;
	D[1] = 3;
	for (int i = 2; i <= N; i++) {
		D[i] = 2 * D[i - 1] + D[i - 2];
		D[i] %= mod;
	}
	printf("%d", D[N]);

	return 0;
}