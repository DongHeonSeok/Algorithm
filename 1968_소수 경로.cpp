#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int queue[1000000];
int ans[1000000];
int prime[10001];
int main()
{
	for (int i = 2; i <= 10000; i++) {
		if (prime[i] == false) {
			for (int j = i*i; j <= 10000; j += i) {
				prime[j] = true;
			}
		}
	}
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 1000000; j++) {
			queue[j] = 0;
			ans[j] = 0;
		}
		int N, M;

		scanf("%d %d", &N, &M);

		int front = 0;
		int rear = 0;
		int pos = 0;
		queue[front] = N;
		bool impossible = true;
		while (front <= rear) {
			pos = queue[front];
			if (pos == M) {
				impossible = false;
				//printf("%d\n", front);
				break;
			}
			//1
			int one = pos;
			int check = one % 10;

			for (int j = 0; j <= 9; j++) {
				if (j != check) {
					int temp = one - check + j;

					if (prime[temp] == 0 && ans[temp] == 0) {
						rear++;
						queue[rear] = temp;
						ans[temp] = ans[pos] + 1;
					}
				}
			}
			//10
			int ten = pos;
			check = ten / 10 % 10;

			for (int j = 0; j <= 9; j++) {
				if (j != check) {
					int temp = ten - (check * 10) + (j * 10);
					if (prime[temp] == 0 && ans[temp] == 0) {

						rear++;
						queue[rear] = temp;
						ans[temp] = ans[pos] + 1;
					}
				}

			}
			//100
			int hund = pos;
			check = hund / 10 / 10 % 10;

			for (int j = 0; j <= 9; j++) {
				if (j != check) {
					int temp = hund - (check * 100) + (j * 100);
					if (prime[temp] == 0 && ans[temp] == 0) {

						rear++;
						queue[rear] = temp;
						ans[temp] = ans[pos] + 1;
					}
				}

			}

			//1000
			int thou = pos;
			check = thou / 10 / 10 / 10 % 10;

			for (int j = 1; j <= 9; j++) {
				if (j != check) {
					int temp = thou - (check * 1000) + (j * 1000);
					if (prime[temp] == 0 && ans[temp] == 0) {

						rear++;
						queue[rear] = temp;
						ans[temp] = ans[pos] + 1;
					}
				}

			}

			front++;
		}
		if (impossible) {
			printf("Impossible\n");
		}
		else {
			printf("%d\n", ans[M]);
		}
	}



	return 0;
}
