#include <cstdio>
using namespace std;
int p[300010];
int a[300010];

int Find(int x)
{
	if (x == p[x]) return x;
	else return p[x] = Find(p[x]);
}
void Union(int x, int y)
{
	printf("LADICA\n");
	x = Find(x);
	y = Find(y);
	p[x] =y;
}

int main()
{
	int N, L;
	scanf("%d %d", &N, &L);
	for (int i = 1; i <= L; i++) {
		p[i] = i;
	}
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (!a[x]) {
			a[x] = 1;
			Union(x, y);
		}
		else if (!a[y]) {
			a[y] = 1;
			Union(y, x);
		}
		else if (!a[Find(x)]) {
			a[Find(x)] = 1;
			Union(x, y);
		}
		else if (!a[Find(y)]) {
			a[Find(y)] = 1;
			Union(y, x);
		}
		else {
			printf("SMECE\n");
		}
	}

	return 0;
}
