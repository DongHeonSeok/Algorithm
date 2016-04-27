// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
using namespace std;
int a[1000100];
int c[1000100];
int q[1000100][2];
/*void init()
{
	for (int i = 0; i < 1000100; i++) {
		a[i] = c[i] = 0;
		q[i][0] = q[i][1] = 0;
	}
}*/
void bfs(int N, int K)
{
	int front = 0;
	int rear = 0;
	q[front][0] = 0;
	q[front][1] = -1;
	while (front <= rear) {
		int val = q[front][0];
		int idx = q[front][1];

		for (int i = idx+1; i < N; i++) {
			if (a[i] - a[idx] <= K && c[i] == 0) {
				rear++;
				c[i] = c[idx] + 1;
				q[rear][0] = a[i];
				q[rear][1] = i;
			}
			else
				break;
			
		}
		front++;
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

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		// �� �κп��� �˰��� ���α׷��� �ۼ��Ͻʽÿ�.
		//init();
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &a[i]);
		}
		int K;
		scanf("%d", &K);

		bfs(N, K);


		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		if (c[N - 1] == 0) {
			printf("-1\n");
		}
		else {
			printf("%d\n", c[N - 1]);
		}

		for (int i = 0; i < N; i++) {
			a[i] = c[i] = 0;
			q[i][0] = q[i][1] = 0;
		}
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}