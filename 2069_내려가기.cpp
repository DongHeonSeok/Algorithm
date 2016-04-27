#include <cstdio>
#define MAX(a,b) ((a)>(b)? (a):(b))
#define MIN(a,b) ((a)>(b)? (b):(a))
using namespace std;
int a[100000][3];
int min[2][3];
int max[2][3];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		if (i == 0) {
			min[0][0] = max[0][0] = a[0][0];
			min[0][1] = max[0][1] = a[0][1];
			min[0][2] = max[0][2] = a[0][2];
		}
		else {
			min[1][0] = min[1][1] = min[1][2] = 0x7fffffff;
		}
	}
	int t = 1;
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			if (j == 0) {
				max[t][0] = MAX(max[t][0], max[!t][0] + a[i][0]);
				max[t][1] = MAX(max[t][1], max[!t][0] + a[i][1]);
				min[t][0] = MIN(min[t][0], min[!t][0] + a[i][0]);
				min[t][1] = MIN(min[t][1], min[!t][0] + a[i][1]);
			}
			else if (j == 1) {
				max[t][0] = MAX(max[t][0], max[!t][1] + a[i][0]);
				max[t][1] = MAX(max[t][1], max[!t][1] + a[i][1]);
				max[t][2] = MAX(max[t][2], max[!t][1] + a[i][2]);
				min[t][0] = MIN(min[t][0], min[!t][1] + a[i][0]);
				min[t][1] = MIN(min[t][1], min[!t][1] + a[i][1]);
				min[t][2] = MIN(min[t][2], min[!t][1] + a[i][2]);
			}
			else {
				max[t][1] = MAX(max[t][1], max[!t][2] + a[i][1]);
				max[t][2] = MAX(max[t][2], max[!t][2] + a[i][2]);
				min[t][1] = MIN(min[t][1], min[!t][2] + a[i][1]);
				min[t][2] = MIN(min[t][2], min[!t][2] + a[i][2]);
			}
		}
		t = !t;
		min[t][0] = min[t][1] = min[t][2] = 0x7fffffff;
	}
	int x = 0;
	int y = 0x7fffffff;
	t = !t;
	for (int i = 0; i<3; i++) {
		if (max[t][i]>x)
			x = max[t][i];
	}
	for (int i = 0; i < 3; i++) {
		if (min[t][i] < y)
			y = min[t][i];
	}
	printf("%d %d\n", x, y);
	return 0;
}
