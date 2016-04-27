#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int arr[27] = { 0, };
	char str[1001] = { 0, };

	for (int i = 0; i < T; i++) {

		for (int j = 0; j < 27; j++) {
			arr[j] = 0;
		}
		for (int j = 0; j < 1001; j++) {
			str[j] = 0;
		}
		cin >> str;

		int len = strlen(str);

		for (int j = 0; j < len; j++) {
			arr[str[j] - 'A']++;
		}

		int sum = 0;
		for (int j = 0; j < 26; j++) {
			if (arr[j] == 0) {
				sum += j + 65;
			}
		}
		printf("%d\n", sum);
	}
	


	return 0;
}