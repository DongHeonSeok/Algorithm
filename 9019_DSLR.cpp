#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int queue[10001];
char cmd[10001];
int check[10001];
int v[10001];
int func_D(int val)
{
	int ret = (val * 2) % 10000;
	
	return ret;
}
int func_S(int val)
{
	int ret = val - 1;
	if (ret < 0)
		ret = 9999;
	return ret;
}
int func_L(int val)
{
	int a, b, c, d;
	a = val / 10 / 10 / 10 % 10;
	b = val / 10 / 10 % 10;
	c = val / 10 % 10;
	d = val % 10;
	
	int ret = b * 1000 + c * 100 + d * 10 + a;
	return ret;
}
int func_R(int val)
{
	int a, b, c, d;
	a = val / 10 / 10 / 10 % 10;
	b = val / 10 / 10 % 10;
	c = val / 10 % 10;
	d = val % 10;

	int ret = d * 1000 + a * 100 + b * 10 + c;
	return ret;
}
int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		for (int i = 0; i < 10001; i++) {
			cmd[i] = 0;
			queue[i] = 0;
			check[i] = 0;
			v[i] = 0;
			
		}
		
		int A, B;
		scanf("%d %d", &A, &B);
		
		int front = 0;
		int rear = 0;
		int pos = 0;
		int ret = 0;
		queue[front] = A;
		v[A] = -1;
		while (front <= rear) {
			pos = queue[front];
			
			if (pos == B) {
				break;
			}
			//d
			
			ret = func_D(pos);
			if (check[ret] == 0) {
				rear++;
				queue[rear] = ret;
				cmd[ret] = 'D';
				check[ret] = 1;
				v[ret] = pos;
			}
			//s
			ret = func_S(pos);
			if (check[ret] == 0) {
				rear++;
				queue[rear] = ret;
				cmd[ret] = 'S';
				check[ret] = 1;
				v[ret] = pos;
			}
			//l
			ret = func_L(pos);
			if (check[ret] == 0) {
				rear++;
				queue[rear] = ret;
				cmd[ret] = 'L';
				check[ret] = 1;
				v[ret] = pos;
			}
			//r
			ret = func_R(pos);
			if (check[ret] == 0) {
				rear++;
				queue[rear] = ret;
				cmd[ret] = 'R';
				check[ret] = 1;
				v[ret] = pos;
			}
			front++;
		}
		string ans = "";
		while (A != B) {
			ans += cmd[B];
			B = v[B];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}


	return 0;
}
