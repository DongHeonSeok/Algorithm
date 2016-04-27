#include <cstdio>
using namespace std;
int p[1000010];

int Find(int x)
{
	if (x == p[x]) return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y)
{
	x = Find(x);
	y = Find(y);
	p[y] = x;
}
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int idx, a, b;
		scanf("%d %d %d", &idx, &a, &b);
		if (idx == 0) {
			Union(a, b);
		}
		else {
			a = Find(a);
			b = Find(b);
			if (a == b)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}