#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int arr[102][2];
int map[102][2];
int main()
{
	int N, I, M;

	scanf("%d %d %d", &N, &I, &M);
	vector<int> x(M);
	vector<int> y(M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		x[i] = arr[i][0] = a;
		y[i] = arr[i][1] = b;

	}

	I = I / 2;
	int w = 1;
	for (int i = 0; i < I - 1; i++) {

		map[i][0] = w;
		map[i][1] = I - w;
		w++;
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int max = 0;
	int count = 0;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < I - 1; k++) {
				int a = x[i] + map[k][0];
				int b = y[j] + map[k][1];

				for (int l = 0; l < M; l++) {
					if ((arr[l][0] >= x[i] && arr[l][0] <= a) && (arr[l][1] >= y[j] && arr[l][1] <= b)) {
						count++;
					}
				}

				if (max < count)
					max = count;
				count = 0;
			}
		}
	}
	printf("%d\n", max);

	return 0;
}