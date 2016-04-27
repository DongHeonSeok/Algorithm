#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int t[510];
int c[510];
int a[510];
vector<int> v[510];
int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &t[i]);
		while (1) {
			int x;
			scanf("%d", &x);
			if (x == -1)
				break;
			v[x].push_back(i);
			c[i]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (c[i] == 0) {
			q.push(i);
			a[i] = t[i];
		}
	}
	for (int i = 1; i <= N; i++) {
		int x = q.front();
		q.pop();
		for (int j = 0; j<(int)v[x].size(); j++) {
			int y = v[x][j];
			c[y]--;
			if (c[y] == 0) {
				q.push(y);
			}
			if (a[x] + t[y] > a[y])
				a[y] = a[x] + t[y];
		}
	}
	for (int i = 1; i <= N; i++) {
		printf("%d\n", a[i]);
	}
	return 0;
}