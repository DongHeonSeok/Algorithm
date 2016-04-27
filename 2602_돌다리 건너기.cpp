#include <iostream>
#include <cstdio>
using namespace std;
int main(void)
{
	char p[30], s1[200], s2[200];
	scanf("%s", p);
	scanf("%s", s1);
	scanf("%s", s2);
	int d[30][2] = { 1, 1 };
	int l;
	for (l = 0; p[l] != NULL; l++);
	int loop_1, loop_2;
	for (loop_1 = 0; s1[loop_1] != NULL; loop_1++)
	{
		for (loop_2 = l - 1; loop_2 >= 0; loop_2--)
		{
			if (s1[loop_1] == p[loop_2])
			{
				d[loop_2 + 1][1] += d[loop_2][0];
			}
			if (s2[loop_1] == p[loop_2])
			{
				d[loop_2 + 1][0] += d[loop_2][1];
			}
		}
	}
	printf("%d", d[l][0] + d[l][1]);
	return 0;
}