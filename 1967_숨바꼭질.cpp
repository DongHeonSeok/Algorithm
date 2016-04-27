#include <iostream>
#include <cstdio>

using namespace std;
int queue[1000000];
int check[1000000];
int main()
{
	int N, K;

	scanf("%d %d", &N, &K);

	int time = 0;

	int front = 0;
	int rear = 0;
	int pos = 0;
	int end = 0;
	queue[front] = N;
	while (front <= rear) {
		pos = queue[front];
		if (pos == K) {
			break;
		}

		if (pos - 1 >= 0) {
			if (check[pos-1] == false) {
				rear++;
				queue[rear] = pos - 1;
				check[pos - 1] = check[pos] + 1;
			}
		}

		if (pos + 1 <= 100000) {
			if (check[pos + 1] == false) {
				rear++;
				queue[rear] = pos + 1;
				check[pos + 1] = check[pos] + 1;
			}
		}

		if (pos * 2 <= 100000) {
			if (check[pos * 2] == false) {
				rear++;
				queue[rear] = pos * 2;
				check[pos * 2] = check[pos] + 1;
			}
		}

		front++;
	}

	printf("%d\n", check[K]);






	return 0;
}