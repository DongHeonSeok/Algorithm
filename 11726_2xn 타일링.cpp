#include <cstdio>
using namespace std;
int d[1010];
int main()
{
	int N;
	scanf("%d", &N);
	d[1] = 1;
	d[2] = 2;
	for (int i = 3; i <= N; i++) {
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 10007;
	}
	printf("%d\n", d[N]);
	return 0;
}