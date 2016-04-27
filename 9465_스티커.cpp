#include <cstdio>
using namespace std;
int d[100010][2];
int a[100010][2];
int MAX(int a, int b)
{
	if (a > b) return a;
	else return b;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &d[j][i]);
				
			}
		}
		a[0][0] = d[0][0];
		a[0][1] = d[0][1];
		for (int i = 1; i < N; i++) {
			a[i][0] = MAX(a[i - 1][0], d[i][0] + a[i - 1][1]);
			a[i][1] = MAX(a[i - 1][1], d[i][1] + a[i - 1][0]);
		}
		printf("%d\n", MAX(a[N - 1][0], a[N - 1][1]));
	}
	return 0;
}