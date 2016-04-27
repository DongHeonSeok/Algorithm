#include <cstdio>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

int main()
{
	string A, B;
	string tmp_A, tmp_B;
	cin >> A >> B;
	int a = 0, b = 0;
	tmp_A = A;
	tmp_B = B;
	for(int i=0; i<(int)A.length(); i++) 
		if (A[i] == '5') A[i] = '6';
	for(int i=0; i<(int)B.length(); i++) 
		if (B[i] == '5') B[i] = '6';

	for (int i = 0; i < (int)A.length(); i++)
		a += pow((double)10, A.length() - i - 1) * (A[i] - '0');
	for (int i = 0; i < (int)B.length(); i++)
		b += pow((double)10, B.length() - i - 1) * (B[i] - '0');
	int max = a + b;
	A = tmp_A, B = tmp_B;
	for (int i = 0; i < (int)A.length(); i++) 
		if (A[i] == '6') A[i] = '5';
	for (int i = 0; i < (int)B.length(); i++) 
		if (B[i] == '6') B[i] = '5';
	
	a = 0, b = 0;
	for (int i = 0; i < (int)A.length(); i++)
		a += pow((double)10, A.length() - i - 1) * (A[i] - '0');
	for (int i = 0; i < (int)B.length(); i++)
		b += pow((double)10, B.length() - i - 1) * (B[i] - '0');
	int min = a + b;
	printf("%d %d", min, max);
	int ac = 1;

	return 0;
}