#include <cstdio>
#include <math.h>
using namespace std;
long long a[1000000];
bool c[5000001];
int main()
{
	long long min, max;
	scanf("%lld %lld", &min, &max);
	int pos = 0;
	for (long long i = 2;; i++) {
		if (i*i > max)
			break;
		a[pos] = i*i;
		pos++;
	}
	int ans = 0;
	for (long long i = 0; i < pos; i++) {
		for (long long j = (min/a[i]) * a[i]; j <= max; j += a[i]) {
			if (j - min < 0) continue;
			if (c[j - min] == 0) {
				c[j - min] = 1;
				ans++;
			}
		}
	
	}
	printf("%lld", max - min - ans+ 1);
	return 0;
}