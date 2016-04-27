#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);

	int ans = 1;

	for(int i=N; i>=1; i--) {
		ans *= i;
	}
	printf("%d\n",ans);
	return 0;
}