#include <cstdio>
using namespace std;
#define MIN(a,b) ((a)>(b)? (b):(a))
int a[10010][3];
int m[10010];
int main()
{
	int N, D;
	scanf("%d %d", &N, &D);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
	}
	for (int i = 1; i <= D; i++) {
		m[i] = m[i - 1] + 1;
		for (int j = 0; j < N; j++) {
			if (a[j][1] == i) {
				m[i] = MIN(m[i], m[a[j][0]] + a[j][2]);
			}
		}
	}
	printf("%d\n", m[D]);
	return 0;
}