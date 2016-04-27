#include <cstdio>
using namespace std;
int d[1000100];
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		int num = i;
		int sum = i;
		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}
		if (d[sum] != 0) {
			if (d[sum] > i)
				d[sum] = i;
		}
		else
			d[sum] = i;
	}
	printf("%d\n", d[N]);


	return 0;
}