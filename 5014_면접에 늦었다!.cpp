#include <iostream>
#include <cstdio>

using namespace std;
int queue[1000001];
int check[1000001];
int main()
{
	int f, s, g, u, d;
	scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);

	int front = 0;
	int rear = 0;
	bool current = false;
	
	queue[front] = s;
	check[s] = 1;
	while(front<=rear) {
		int pos = queue[front];
		if(s==g) {
			current = true;
			break;
		}
		if(pos==g)
			break;

		if(pos+u<=f && check[pos+u] == 0) {
			rear++;
			queue[rear] = pos+u;
			check[pos+u] = check[pos] +1;
		}

		if(pos-d>=1 && check[pos-d]==0) {
			rear++;
			queue[rear] = pos-d;
			check[pos-d] = check[pos]+1;
		}
			
		front++;
	}
	if(current) {
		printf("0\n");
	}
	else if(check[g] == 0) {
		printf("use the stairs\n");
	}
	else {
		printf("%d\n", check[g]-1);
	}

	return 0;
}