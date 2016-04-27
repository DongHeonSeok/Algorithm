#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<int> a[32001];
int c[32001];
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		a[x].push_back(y);
		c[y]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (c[i] == 0) {
			q.push(i);
		}
	}

	for (int i = 0; i < N; i++) {
		int x = q.front();
		printf("%d ", x);
		q.pop();

		for (int j = 0; j < (int)a[x].size(); j++) {
			int y = a[x][j];
			c[y]--;
			if (c[y] == 0) {
				q.push(y);
			}
		}
	}
	printf("\n");
	return 0;
}