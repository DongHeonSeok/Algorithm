#include <cstdio>
using namespace std;
int d[40];
int main()
{
	int N;
	scanf("%d", &N);

	d[0] = 1;
	d[2] = 3;
	for (int i = 4; i <= N; i += 2) {
		d[i] = 3 * d[i - 2];
		for (int j = 4; j <= i; j += 2) {
			d[i] += 2 * d[i - j];
		}
	}
	printf("%d\n", d[N]);
	return 0;
}