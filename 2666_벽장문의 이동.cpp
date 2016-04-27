#include <cstdio>
#include <queue>
using namespace std;
struct pos
{
	int x;
	int y;
	int z;
};
queue<pos> q;
int ABS(int x)
{
	if (x < 0) return -x;
	else return x;
}
int main()
{
	int a[21];
	int N, M;
	scanf("%d", &N);
	int left, right;
	scanf("%d %d", &left, &right);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a[i]);
	}
	pos p;
	p.x = left;
	p.y = right;
	p.z = 0;
	q.push(p);
	int min = 987654321;
	for (int i = 0; i < M; i++) {
		int idx = a[i];
		int cnt = q.size();
		while (cnt--) {
			pos temp;
			temp.x = q.front().x;
			temp.y = q.front().y;
			temp.z = q.front().z;
			q.pop();

			if (idx <= temp.x) {
				p.x = idx;
				p.y = temp.y;
				p.z = ABS(idx - temp.x) + temp.z;
				q.push(p);
			}
			if (idx >= temp.x && idx <= temp.y) {
				//left
				p.x = idx;
				p.y = temp.y;
				p.z = ABS(idx - temp.x) + temp.z;
				q.push(p);
				//right
				p.x = temp.x;
				p.y = idx;
				p.z = ABS(idx - temp.y) + temp.z;
				q.push(p);
			}
			if (idx >= temp.y) {
				p.x = temp.x;
				p.y = idx;
				p.z = ABS(idx - temp.y) + temp.z;
				q.push(p);
			}
		}
	}
	while (!q.empty()) {
		p = q.front();
		q.pop();
		if (min > p.z)
			min = p.z;
	}
	printf("%d\n", min);
	return 0;
}