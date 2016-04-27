#include <cstdio>
using namespace std;
int A[20];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	int ans = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (K%A[i] != K) {
			ans += K/A[i];
			K %= A[i];
		}
	}
	printf("%d", ans);
	return 0;
}