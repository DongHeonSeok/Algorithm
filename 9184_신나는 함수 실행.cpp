#include <iostream>
#include <cstdio>

using namespace std;

int map[100][100][100];

int search(int a, int b, int c)
{
	if(a<=0 || b<=0 || c<=0)
		return 1;
	if(a>20 || b> 20 || c>20)
		 return search(20, 20, 20);
	if(map[a][b][c] >0) 
		return map[a][b][c];
	
	if(a<b && b<c) 
		map[a][b][c] =  search(a, b, c-1) + search(a, b-1, c-1) - search(a, b-1, c);
	else 
		map[a][b][c] = search(a-1, b, c) + search(a-1, b-1, c) + search(a-1, b, c-1) - search(a-1, b-1, c-1);

	return map[a][b][c];
}
int main()
{
	int a, b, c;

	while(1) {
		scanf("%d %d %d", &a, &b, &c);

		if(a==-1 && b==-1 && c==-1)
			break;

		if(a<=0 || b<=0 || c<=0) {
			printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
		}
		else {
			printf("w(%d, %d, %d) = %d\n", a, b, c, search(a, b, c));
		}

	}

	return 0;
}

