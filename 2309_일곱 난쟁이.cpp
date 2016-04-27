#include<iostream>
using namespace std;
#define MAX 9
#define SWAP(A, B){int T; T = A; A = B; B = T;}

int datas[MAX + 1] = { 0 };
int tot = 0;
void input()
{
	for (int i = 0; i < MAX; i++)
	{
		cin >> datas[i];
		tot += datas[i];
	}
}
void sort()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (datas[i] < datas[j]) SWAP(datas[i], datas[j]);
}
void print()
{
	for (int i = 0; i < MAX; i++)
		if (datas[i] != 0) cout << datas[i] << endl;
}
void solve()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 1; j < MAX; j++)
			if (datas[i] + datas[j] == tot - 100)
				datas[i] = datas[j] = 0;
}

int main()
{
	input();
	solve();
	sort();
	print();
	return 0;
}