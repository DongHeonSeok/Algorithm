/*

VCPP, GPP���� ���

*/

#include <iostream>
#include <cstdio>
using namespace std;
int func(int d, int h, int m)
{
	if (d == 11 && h < 11)
		return -1;
	else if (d==11 && h >= 11 && m < 11)
		return -1;

	int ret = 0;
	ret += (d - 11) * 24*60;
	ret += (h - 11) * 60;
	ret += (m - 11);
	return ret;
}
int main()
{

	int nCount;		/* ������ �׽�Ʈ ���̽� */

	cin >> nCount;	/* �׽�Ʈ ���̽� �Է� */

	for (int itr = 0; itr < nCount; itr++)
	{

		cout << "#testcase" << (itr + 1) << endl;

		int d, h, m;
		scanf("%d %d %d", &d, &h, &m);

		int ans = func(d, h, m);
		if (ans == -1)
			printf("-1\n");
		else
			printf("%d\n", ans);

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}