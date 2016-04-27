#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);

	char arr[2] = { 'F', '9' };
	
	if (N < 2013) {
		for (int i = 2013; i > N; i--) {
			char x = arr[0];
			char y = arr[1];

			if (x == 'A')
				x = 'L';
			else
				x = x - 1;

			if (y == '0')
				y = '9';
			else
				y = y - 1;

			arr[0] = x;
			arr[1] = y;
		}
	}
	else {
		for (int i = 2013; i < N; i++) {
			char x = arr[0];
			char y = arr[1];

			if (x == 'L')
				x = 'A';
			else
				x = x + 1;

			if (y == '9')
				y = '0';
			else
				y = y + 1;

			arr[0] = x;
			arr[1] = y;
		}
	}
	printf("%c%c", arr[0], arr[1]);

	return 0;
}