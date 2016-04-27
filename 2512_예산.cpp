#include <cstdio>
using namespace std;
int a[10100];
int main()
{
	int N, M, max = 0, sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (a[i]>max) max = a[i];
		sum += a[i];
	}
	scanf("%d", &M);
	if (sum <= M)
		printf("%d\n", max);
	else {
		int ans = 0;
		int left = 1;
		int right = max;
		int cnt = 0;
		sum = 0;
		while (left <= right) {
			int mid = (left + right) / 2;
			for (int i = 0; i < N; i++) {
				if (a[i] < mid)
					sum += a[i];
				else
					sum += mid;
			}
			if (sum <=M) {
				if (mid > ans)
					ans = mid;
				left = mid + 1;
			}
			else
				right = mid - 1;
			sum = 0;
		}
		printf("%d\n", ans);
	}
		
	return 0;
}