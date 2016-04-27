#include <cstdio>
using namespace std;
char C[100010];
void quick(int start, int end, char x[])
{
	char p = x[(start + end) / 2];
	int s = start;
	int e = end;
	while (s <= e) {
		while (x[s] > p && s <= e) s++;
		while (p > x[e] && s <= e) e--;
		if (s <= e) {
			char tmp = x[s];
			x[s] = x[e];
			x[e] = tmp;
			s++; e--;
		}
	}
	if (start < e) quick(start, e, x);
	if (s < end) quick(s, end, x);
}
int main()
{
	scanf("%s", C);
	int len = 0;
	for (len = 0; C[len] != '\0'; len++);
	int sum = 0;
	for (int i = 0; i < len; i++) 
		sum += C[i] - '0';
	quick(0, len - 1, C);
	if (C[len - 1] == '0' && sum%3==0) 
		printf("%s", C);
	else
		printf("-1");
	return 0;
}