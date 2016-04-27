#include <cstdio>
using namespace std;
long long a[100010];
long long d[100010];

int main()
{
	long long N;
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i]);
	}
	d[0] = a[0];
	long long max = d[0];
	for (int i = 1; i < N; i++) {
		if (d[i - 1] + a[i]>a[i])
			d[i] = d[i - 1] + a[i];
		else
			d[i] = a[i];
		if (d[i]>max)
			max = d[i];
	}
	printf("%lld\n", max);

	return 0;
}