#include <cstdio>
using namespace std;
int a[1010];
int b[1010];
int d[1010];
int main()
{
	int N; 
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &d[i]);
	}
	int max = 0;
	for (int i = 0; i < N; i++) {
		a[i] = 1;
		for (int j = 0; j < i; j++) {
			if (d[i]>d[j] && a[j] + 1>a[i])
				a[i] = a[j] + 1;
		}
		if (a[i] > max) 
			max = a[i];
	}
	max = 0;
	for (int i = N - 1; i >= 0; i--) {
		b[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (d[i] > d[j] && b[j] + 1 > b[i])
				b[i] = b[j] + 1;
		}
		if (b[i] > max) 
			max = b[i];
	}
	max = 0;
	for (int i = 0; i<N; i++) {
		if (a[i] + b[i] - 1 >max)
			max = a[i] + b[i] - 1;
	}
	printf("%d\n", max);
	return 0;
}