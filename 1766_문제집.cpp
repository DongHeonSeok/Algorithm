#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
vector<int> a[32010];
int c[32010];

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
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 1; i <= N; i++) {
		if (c[i] == 0) 
			pq.push(i);
	}

	for (int i = 0; i < N; i++) {
		int x = pq.top();
		printf("%d ", x);
		pq.pop();
		for (int i = 0; i < (int)a[x].size(); i++) {
			int y = a[x][i];
			c[y]--;
			if (c[y] == 0) {
				pq.push(y);
			}
		}
	}
	return 0;
}