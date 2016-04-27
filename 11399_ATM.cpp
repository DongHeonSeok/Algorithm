#include <cstdio>
#include <algorithm>
using namespace std;
long long A[1010];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	sort(A, A + N);
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			ans += A[j];
		}
	}
	printf("%lld", ans);
	return 0;
}
