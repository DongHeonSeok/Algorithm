#include <cstdio>
#include <algorithm>
using namespace std;
int s[20];
int w[20][20];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		s[i] = i + 1;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &w[i][j]);
		}
	}
	int sum = 0;
	int min = 0x7fffffff;
	do
	{
		sum = 0;
		bool possible = true;
		for (int i = 1; i < N; i++) {
			if (w[s[i-1] - 1][s[i]-1] != 0) {
				sum += w[s[i - 1] - 1][s[i] - 1];
			}
			else {
				possible = false;
				break;
			}
		}
		if (w[s[N - 1]-1][s[0]-1] != 0) {
			sum += w[s[N - 1]-1][s[0]-1];
		}
		else {
			possible = false;
		}
		if (possible) {
			if (min > sum)
				min = sum;
		}
	} while (next_permutation(s, s+N));

	printf("%d\n", min);

	return 0;
}