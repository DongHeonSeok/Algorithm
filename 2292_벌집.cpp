#include <iostream>
#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);

	int count = 1;
	int sprev = 1;
	int fprev = 1;
	if(N==1) {
		printf("1\n");
		return 0;
	}
	else {
		while(1) {
			int start = sprev + 6*(count-1);
			int finish = fprev + 6*(count);

			if(N>=start && N<=finish) {
				printf("%d\n", count+1);
				return 0;
			}
			count++;
			sprev = start;
			fprev = finish;
		}
	}
	return 0;
}