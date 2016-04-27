#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	int T;
	scanf("%d", &T);

	while(T--) {
		int W, H, N;
		int a = 0, b = 1;
		int flag = 0;
		scanf("%d %d %d", &H, &W, &N);

		while(N--) {
			if(a==H) {
				a = 0;
				b++;
			}
			a++;
		}
		printf("%d", a);
		if(b<10) {
			printf("0%d\n", b);
		}
		else {
			printf("%d\n",b);
		}
	}
	return 0;
}