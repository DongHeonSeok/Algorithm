#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);

	for(int i=0; i<T; i++) {
		int N, M;
		int queue[100001] = {0, };
		scanf("%d %d", &N, &M);

		for(int i=0; i<N; i++) {
			scanf("%d", &queue[i]);
		}
		int front = 0;
		int rear = N-1;
		int pos = M;
		int count = 0;
		int check = 0;
		int ans = 0;
		while(front<=rear) {
			int top = queue[front];

			for(int i=front; i<=rear; i++) {
				if(top<queue[i]) {
					check = 1;
					break;
				}
			}
			if(check == 1) {
				rear++;
				queue[rear] = queue[front];
				if(front==pos) {
					pos = rear;
				}
				front++;
				check = 0;
			}
			else {
				count++;
				if(front==pos) {
					ans = count;
					break;
				}
				else {
					front++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
