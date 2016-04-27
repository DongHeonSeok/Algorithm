#include <cstdio>
int a[1010];
int d[1010];
int main()
{
	int N, max = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; i++) {
		d[i] = 1;
		for (int j = 0; j<i; j++) {
			if (a[i]<a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
		if (d[i] > max)
			max = d[i];
	}
	printf("%d\n", max);

	return 0;
}