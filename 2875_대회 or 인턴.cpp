#include <cstdio>
using namespace std;
int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	int ans = 0;
	while (N>=2 && M>=1 && N + M >= K + 3) {
		ans++;
		N -= 2;
		M -= 1;
	}
	printf("%d", ans);

	return 0;
}