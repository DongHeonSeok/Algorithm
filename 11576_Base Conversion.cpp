#include <cstdio>
#include <math.h>
using namespace std;
int d[30];
int x[30];
int main()
{
	int A, B;
	scanf("%d %d", &A, &B);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &d[i]);
	}
	unsigned int idx = 0;
	for (int i = 0; i < m; i++) {
		idx += (unsigned int)pow((double)A, m-i-1) * d[i];
	}
	int pos = 0;
	while (idx != 0) {
		x[pos] = idx%B;
		idx /= B;
		pos++;
	}
	for (int i = pos - 1; i >= 0; i--) {
		printf("%d ", x[i]);
	}
	return 0;
}