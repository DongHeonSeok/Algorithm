#include <cstdio>
using namespace std;
long long a[3];
long long b[3];
int c[3];
int MIN(int a, int b)
{
	if (a > b)return b;
	else return a;
}
int main()
{
	int cnt = 0;
	while (1) {
		
		cnt++;
		int N;
		scanf("%d", &N);
		if (N == 0)
			break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 3; j++) {
				scanf("%d", &c[j]);
			}
			if (i == 0) {
				a[0] = c[1];
				a[1] = c[1];
				a[2] = c[1];
				if (c[2] < 0)
					a[2] = a[1] + c[2];
			}
			else if (i == 1) {
				a[0] += c[0];
				a[1] = c[1] + MIN(b[1], b[2]);
				a[2] = c[2] + MIN(b[1], b[2]);

				a[1] = MIN(a[1], a[0] + c[1]);
				a[2] = MIN(a[2], a[1] + c[2]);
			}
			else {

				a[0] = c[0] + MIN(b[0], b[1]);
				a[1] = c[1] + MIN(b[0], MIN(b[1], b[2]));
				a[2] = c[2] + MIN(b[1], b[2]);

				a[1] = MIN(a[1], a[0] + c[1]);
				a[2] = MIN(a[2], a[1] + c[2]);

			}
			b[0] = a[0];
			b[1] = a[1];
			b[2] = a[2];
		}
		printf("%d. %d\n", cnt, a[1]);
	}



	return 0;
}