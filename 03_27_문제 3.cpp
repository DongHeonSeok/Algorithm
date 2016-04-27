/*

VCPP, GPP에서 사용

*/

#include <iostream>
using namespace std;
long long arr[100001][2];
int ABS(int num)
{
	if (num < 0)
		return -num;
	else
		return num;
}
int func(int num)
{
	int left = 1;
	int right = 1;
	int gap_l = 1;
	int gap_r = 2;
	int lev = 1;
	while (1) {
		if (num >= left && num <= right)
			return lev;
		
		left = left + gap_l;
		right = right + gap_r;
		gap_l++;
		gap_r++;
		lev++;
	}
}
int main()
{

	int nCount;		/* 문제의 테스트 케이스 */

	cin >> nCount;	/* 테스트 케이스 입력 */

	for (int itr = 0; itr<3; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		long long left = 1, right = 1;
		long long gap_l = 1, gap_r = 2;
		arr[1][0] = arr[1][1] = 1;
		for (int i = 2; i <= 100000; i++) {
			arr[i][0] = arr[i-1][0] + gap_l;
			arr[i][1] = arr[i-1][1] + gap_r;
			gap_l++;
			gap_r++;
		}
		

		

		int ac = 1;
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}