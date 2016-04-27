#include <cstdio>
#include <queue>
using namespace std;
int d[10010];
int v[10010];
struct pos
{
	int idx;
	int num;
	int cost;
};
queue<pos> q;

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &d[i]);
	}
	int a, b;
	scanf("%d %d", &a, &b);
	pos p;
	p.idx = a;
	p.num = d[a];
	p.cost = 0;
	q.push(p);
	int ans = 0;
	bool possible = false;
	while (!q.empty()) {
		p = q.front();
		int num = p.num;
		int idx = p.idx;
		int cost = p.cost;
		q.pop();
		if (p.idx == b) {
			ans = cost;
			possible = true;
			break;
		}
		for (int i = 1;; i++) {
			if (idx + (num*i) > N)
				break;
			else if(v[idx+(num*i)]==0) {
				v[idx + (num*i)] = 1;
				p.idx = idx + (num*i);
				p.cost = cost + 1;
				p.num = d[idx + (num*i)];
				q.push(p);
			}
		}
		for (int i = 1;; i++) {
			if (idx - (num*i) <= 0)
				break;
			else if(v[idx-(num*i)]==0) {
				v[idx - (num*i)] = 1;
				p.idx = idx - (num*i);
				p.cost = cost + 1;
				p.num = d[idx - (num*i)];
				q.push(p);
			}
		}
	}
	if (!possible)
		printf("-1\n");
	else 
		printf("%d\n", ans);
	return 0;
}