#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int pig[8] = { 0, };
	int update[8] = { 0, };
	//test case
	for (int i = 0; i < T; i++) {
		for (int j = 0; j < 8; j++) {
			pig[j] = 0;
			update[j] = 0;
		}

		int N;
		scanf("%d", &N);
		int day = 1;
		int sum = 0;

		for (int j = 1; j < 7; j++) {
			scanf("%d", &pig[j]);
		}

		pig[0] = pig[6];
		pig[7] = pig[1];

		while (1) {
			sum = 0;
			for (int j = 1; j < 7; j++) {
				sum += pig[j];
			}
			if (sum > N)
				break;
			
			for (int j = 1; j < 7; j++) {
				int n = j + 3;
				if (n > 6) {
					n = n - 6;
				}
				update[j] = pig[j] + pig[j - 1] + pig[j + 1] + pig[n];
			}
			for (int j = 1; j < 7; j++) {
				pig[j] = update[j];
			}
			pig[0] = pig[6];
			pig[7] = pig[1];
			day++;
			
		}
		printf("%d\n", day);


	}


	return 0;
}