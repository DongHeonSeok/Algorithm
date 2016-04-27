#include <cstdio>
using namespace std;
int main()
{
	long long d[110] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9, 12, };
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);

		for (int i = 12; i <= N; i++) {
			d[i] = d[i - 5] + d[i - 1];
		}
		printf("%lld\n", d[N]);
	}
	return 0;
}