#include <cstdio>
#include <queue>
using namespace std;
priority_queue <int, vector<int>, less<int> > pq;

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
			}
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}


	return 0;
}