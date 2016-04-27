#include <cstdio>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
long long a[100010];
long long c[100010];
long long d[100010];
void init(int N)
{
	for (int i = 0; i < 100010; i++) {
		a[i] = c[i] = d[i] = 0;
	}
}
int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	/* setbuf �Լ��� ������� ������, ������ ���α׷��� ���� �ð� �ʰ��� ���� ���� �Ǿ��� ��,
	C++���� printf�� ����� ���, printf�� ����� ������ ä������ �ʰ� '0��'�� �� ���� �ֽ��ϴ�.
	���� printf�� ����� ��� setbuf(stdout, NULL) �Լ��� �ݵ�� ����Ͻñ� �ٶ��ϴ�. */
	setbuf(stdout, NULL);

	int T;
	int test_case;

	scanf("%d", &T);	// Codeground �ý��ۿ����� C++������ scanf �Լ� ����� �����ϸ�, cin�� ����ϼŵ� �˴ϴ�.
	for (test_case = 1; test_case <= T; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�. �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.

		int N;
		long long ans = 0;
		long long max = -1;
		long long val = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &a[i]);
			if (i >= 1) {
				val = a[i] - a[i - 1];
				if (val > max)
					max = val;
			}
		}
		long long idx = 0;
		for (long long i = 1; i <= (long long)sqrt(max); i++) {
			if (max%i == 0) {
				c[idx] = i;
				idx++;
				if (i != max / i) {
					c[idx] = max / i;
					idx++;
				}
			}
		}
		sort(c, c + idx);
		bool possible = true;

		for (int i = 1; i < N && possible; i++) {
			val = a[i] - a[i-1];
			if (val == 0) {
				if (c[0] == 0) {
					ans = 1;
					break;
				}
				else {
					possible = false;
					break;
				}
			}
			else {
				for (int j = 0; j < idx; j++) {
					if (val%c[j] == 0)
						d[j]++;
				}
			}
		}
		// �� �κп��� ������ ����Ͻʽÿ�. Codeground �ý��ۿ����� C++������ printf ����� �����ϸ�, cout�� ����ϼŵ� �˴ϴ�.
		printf("Case #%d\n", test_case);

		if (!possible)
			printf("0\n");
		else {
			for (int i = 0; i < idx; i++) {
				if (d[i] == N - 1)
					ans++;
			}
			printf("%lld\n", ans);
		}
		init(N);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}