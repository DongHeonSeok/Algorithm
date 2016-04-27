#include <iostream>

using namespace std;

int main()
{
	int K;
	int map[8][8] = { 0, };
	cin >> K;

	for (int i = 1; i <= 6; i++) {
		cin >> map[i][0] >> map[i][1];
	}

	map[0][0] = map[6][0];
	map[0][1] = map[6][1];
	map[7][0] = map[1][0];
	map[7][1] = map[1][1];
	int max = 0;
	int min = 0x7fffffff;
	int temp1 = 0;
	int temp2 = 0;
	for (int i = 1; i <= 6; i++) {
		if (map[i][0] == 2) {
			if (map[i + 1][0] == 3) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}
		else if (map[i][0] == 3) {
			if (map[i + 1][0] == 1) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}
		else if (map[i][0] == 1) {
			if (map[i + 1][0] == 4) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}
		else if (map[i][0] == 4) {
			if (map[i + 1][0] == 2) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}

		if (temp1 > max)
			max = temp1;
	}
	temp1 = 0x7fffffff;
	for (int i = 1; i <= 6; i++) {
		if (map[i][0] == 3) {
			if (map[i + 1][0] == 2) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}
		else if (map[i][0] == 1) {
			if (map[i + 1][0] == 3) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}
		else if (map[i][0] == 4) {
			if (map[i + 1][0] == 1) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}
		else if (map[i][0] == 2) {
			if (map[i + 1][0] == 4) {
				temp1 = map[i][1] * map[i + 1][1];
			}
		}

		if (temp1 < min)
			min = temp1;
	}
	//printf("%d %d\n", max, min);
	int ans = max - min;
	cout << (ans * K) << endl;
	
	return 0;
}