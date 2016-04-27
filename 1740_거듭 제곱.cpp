#include <cstdio>
using namespace std;
int a[100];
int main()
{
	long long N;
	scanf("%lld", &N);
	int pos = 0;
	for (pos = 0;; pos++) {
		if (N == 0)
			break;
		a[pos] = N % 2;
		N /= 2;
	}
	long long ans = 0;
	long long val = 1;
	for (int i = 0; i < pos; i++) {
		ans += a[i] * val;
		val *= 3;
	}
	printf("%lld\n", ans);

	return 0;
}