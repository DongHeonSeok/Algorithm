#include <cstdio>
using namespace std;
char A[110];
int B[30];
int main()
{
	scanf("%s", A);
	int len = 0;
	for (len = 0; A[len] != '\0'; len++);
	for (int i = 0; i < len; i++)
		B[A[i] - 'a']++;
	for (int i = 0; i < 26; i++)
		printf("%d ", B[i]);
	return 0;
}