#include <iostream>
#include <algorithm>

using namespace std;
int M, N, K;
int map[100][100] = { 0, };
int check[100][100] = { 0, };
int home[10001] = { 0, };

void go(int y, int x, int count)
{
	if (x < 0 || x >= N || y < 0 || y >= M || check[y][x] != 0 || map[y][x] == -1)
		return;

	map[y][x] = count;
	check[y][x] = 1;
	home[count]++;
	go(y - 1, x, count);
	go(y + 1, x, count);
	go(y, x - 1, count);
	go(y, x + 1, count);
}
int main()
{
	cin >> M >> N >> K;

	for (int i = 0; i < K; i++) {
		int s_x, s_y, f_x, f_y;

		cin >> s_x >> s_y >> f_x >> f_y;

		for (int j = s_y; j < f_y; j++) {
			for (int k = s_x; k < f_x; k++) {
				map[j][k] = -1;
				
			}
		}
	}
	  

	int count = 0;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 0 && check[i][j] == 0) {
				count++;
				go(i, j, count);
			}
		}
	}
	
	cout << count << endl;
	
	sort(home, home + count+1);

	for (int i = 1; i < count+1; i++) {
		cout << home[i] << " ";
	}
	cout << endl;

	return 0;
}