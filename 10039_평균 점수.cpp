#include <iostream>
#include <cstdio>

using namespace std;

int data[6];
int main()
{
	for(int i=0; i<5; i++) {
		int val = 0;
		scanf("%d", &val);
		if(val<40)
			val = 40;
		data[i] = val;
	}
	int sum = 0;
	for(int i=0; i<5; i++) {
		sum += data[i];
	}
	printf("%d\n", sum/5);

	return 0;
}
