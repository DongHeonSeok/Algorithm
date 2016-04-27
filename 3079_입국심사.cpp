#include <cstdio>
using namespace std;
long long A[100010];
const long long max = 987654321987654LL;
long long min = 987654321987654LL;
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
	}
	long long left = 0LL;
	long long right = max;
	long long mid;
	
	while (left <= right) {
		mid = (left + right) / 2LL;
		long long sum = 0LL;
		for (int i = 0; i < N; i++) {
			sum += mid / A[i];
		}
		if (sum >= M) {
			if (min > mid)
				min = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	printf("%lld", min);


	return 0;
}