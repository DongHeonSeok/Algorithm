#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string str = "";
	int len = 0;

	cin >> str;

	len = str.length();

	int ans = 10;
	char start = str[0];

	for (int i = 1; i < len; i++) {
		if (start == str[i])
			ans += 5;
		else
			ans += 10;
		start = str[i];
	}

	printf("%d\n", ans);

	return 0;
}