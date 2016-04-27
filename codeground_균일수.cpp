// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;

void func(int N)
{
	if (N == 2) {
		printf("3\n");
		return;
	}
	else if (N == 1 || N == 3) {
		printf("2\n");
		return;
	}

	int sq = (int)sqrt(N);
	for (int i = 2; i <= sq; i++) {
		int t = N;
		int p = N%i;
		if (p == 0) continue;
		bool possible = true;
		while (t > 0) {
			if ((t%i) != p) {
				possible = false;
				break;
			}
			t /= i;
		}
		if (possible) {
			printf("%d\n", i);
			return;
		}
	}
	for (int j = sq; j >= 2; j--) {
		if ((N%j) == 0 && j < (N / j) - 1) {
			printf("%d\n", (N / j) - 1);
			return;
		}
	}
	printf("%d\n", N - 1);
}

int main(int argc, char** argv) {
	/* �Ʒ� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸ� ���� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	���� ������ PC ���� �׽�Ʈ �� ����, �Է°��� input.txt�� ������ �� freopen �Լ��� ����ϸ�,
	�� �Ʒ����� scanf �Լ� �Ǵ� cin�� ����Ͽ� ǥ���Է� ��� input.txt ���Ϸ� ���� �Է°��� �о� �� �� �ֽ��ϴ�.
	����, ���� PC���� freopen �Լ��� ������� �ʰ� ǥ���Է��� ����Ͽ� �׽�Ʈ�ϼŵ� �����մϴ�.
	��, Codeground �ý��ۿ��� "�����ϱ�" �� ������ �ݵ�� freopen �Լ��� ����ų� �ּ�(//) ó�� �ϼž� �մϴ�. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		int N;

		scanf("%d", &N);
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		func(N);
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}