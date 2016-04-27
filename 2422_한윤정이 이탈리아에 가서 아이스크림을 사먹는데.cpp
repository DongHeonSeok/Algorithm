#include <iostream>

using namespace std;

int possible[201][201] = { 0, };

int main()
{
	int N, M;
	int search[3] = { 0, };
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		possible[x][y] = possible[y][x] = 1;
	}

	int count = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = i+1; j <= N; j++) {
			for (int k = j + 1; k <= N; k++) {
			
				if (possible[i][j] == 0 && possible[j][k] == 0 && possible[i][k] == 0) {
					count++;
				}

				
			}
		}
	}

	cout << count << endl;


	return 0;
}