#include <cstdio>
using namespace std;
long long k[22];
bool check[22];
int arr[22];
long long ans = 0;
void first(long long N, long long idx, long long total)
{
	if (N == 1) {
		for (int i = 1; i < total + 1; i++) {
			if (!check[i])
				printf("%d ", i);
		}
	}
	else {
		for (int i = 1; i < total + 1; i++) {
			if (!check[i]) {
				if (idx <= k[N - 1]) {
					check[i] = true;
					printf("%d ", i);
					first(N - 1, idx, total);
					return;
				}
				idx -= k[N - 1];
			}
		}
	}
}
long long second(long long N, long long total)
{
	if (N == 1)
		return 1;
	long long t = 0;
	for (int i = 1; i < total + 1; i++) {
		if (!check[i]) {
			if (i == arr[N]) {
				check[i] = true;
				return second(N - 1, total) + t;
			}
			t += k[N - 1];
		}
	}
}
int main()
{
	k[1] = 1;
	for (long long i = 2; i <= 20; i++) {
		k[i] = k[i - 1] * i;
	}

	long long N;
	scanf("%lld", &N);
	int x;
	scanf("%d", &x);
	if (x == 1) {
		long long idx, total = 0;
		scanf("%lld", &idx);
		total = N;
		first(N, idx, total);
		int ac = 1;
	}
	else {
		for (int i = N; i >= 1; i--) {
			scanf("%d", &arr[i]);
		}
		long long total = N;
		printf("%lld\n", second(N, total));

	}

	return 0;
}
