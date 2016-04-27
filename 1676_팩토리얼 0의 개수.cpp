#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int main()
{
	int N;

	scanf("%d", &N);

	int count = 1;
	int ans = 0;
	while(1) {
		int val = (int)pow((double)5, count);

		if(val>N)
			break;
		ans += N/val;
		count++;
	}

	printf("%d\n", ans);




	return 0;
}