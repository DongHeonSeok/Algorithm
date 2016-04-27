#include <cstdio>
#include <math.h>
using namespace std;
int num[110];
int s[110];
int b[110];
int arr[1000];
int digit1[3];
int digit2[3];
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &num[i], &s[i], &b[i]);
	}

	int ans = 0;
	for (int i = 111; i <= 999; i++) {
		bool possible = true;
		digit2[0] = i / 100;
		digit2[1] = i / 10 % 10;
		digit2[2] = i % 10;
		if (digit2[0] == 0 || digit2[1] == 0 || digit2[2] == 0)
			continue;
		if (digit2[0] == digit2[1] || digit2[1] == digit2[2] || digit2[0] == digit2[2])
			continue;
		for (int j = 0; j < N; j++) {
			digit1[0] = num[j] / 100;
			digit1[1] = num[j] / 10 % 10;
			digit1[2] = num[j] % 10;
			int st = 0; int ba = 0;
			for (int k = 0; k < 3; k++) {
				for (int l = 0; l < 3; l++) {
					if (k == l && digit1[k] == digit2[l])
						st++;
					if (k != l && digit1[k] == digit2[l])
						ba++;
				}
			}
			if (st != s[j] || ba != b[j]) {
				possible = false;
				break;
			}
		}
		if (possible)
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}