#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int data[12] = {0, };
	
	data[0] = 1;
	data[1] = 1;
	data[2] = 2;

	for(int i=3; i<12; i++) {
		data[i] = data[i-1] + data[i-2] + data[i-3];
	}
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", data[n]);
	}

	return 0;
}