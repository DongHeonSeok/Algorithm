#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int map[26][26];
int check[26][26];

void go(int y, int x, int count)
{
	if (x < 0 || x >= N)
		return;

	if (y < 0 || y >= N)
		return;

	if (map[y][x] == 1 && check[y][x] == 0) {
		check[y][x] = count;
	}
	else
		return;
	go(y - 1, x, count);
	go(y + 1, x, count);
	go(y, x - 1, count);
	go(y, x + 1, count);
}
int main()
{
	int home[26*26] = { 0, };
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int count = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			if (map[i][j] == 1 && check[i][j] == 0) {
				go(i, j, count);
				count++;
			}
		}
	}

	for (int k = 1; k <= count - 1; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (check[i][j] == k) {
					home[k-1]++;
				}
			}
		}
	}

	sort(home, home + (count - 1));

	printf("%d\n", count - 1);
	for (int i = 0; i < count - 1; i++) {
		printf("%d\n", home[i]);
	}

	return 0;
}