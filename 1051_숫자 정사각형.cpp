#include <iostream>
#include <cstdio>

using namespace std;
int map[51][51] = { 0, };
int main() {
	int N, M;
	int max = 0;
	int ans = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			flag = 0;
			ans = 0;
			int val = map[i][j];
			int x = 1, y = 1;

			while (i + y < N && j + x < M) {
				int pos_x = j + x;
				int pos_y = i + y;

				if (map[pos_y][pos_x] == val) {
					if (map[pos_y][j] == val && map[i][pos_x] == val) {
						ans = (pos_x - j + 1) * (pos_y - i + 1);
					}

					if (max < ans)
						max = ans;
					flag = 1;
				}
				x++;
				y++;
			}
			if (flag == 0) {
				ans = 1;
				if (max < ans) {
					max = ans;
				}
			}
		}
	}

	printf("%d\n", max);


	return 0;
}