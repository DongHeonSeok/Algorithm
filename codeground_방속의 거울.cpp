// �Ʒ� �⺻ ������ �ڵ带 ���� �Ǵ� �����ϰ� ������ �ڵ带 ����ϼŵ� �˴ϴ�.
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int N;
int m[1010][1010];
int v[1010][1010];
struct pos
{
	int x;
	int y;
	int type; //1-d, 2-u, 3-l, 4-r
};
queue<pos> q;
void init(int N)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			v[i][j] = m[i][j] = 0;
		}
	}
	while (!q.empty()) {
		q.pop();
	}
}
bool range(int y, int x)
{
	if (x >= 0 && y >= 0 && x < N && y < N)
		return true;
	else
		return false;
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

		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%1d ", &m[i][j]);
			}
		}
		int ans = 0;
		pos p;
		p.x = 0;
		p.y = 0;
		p.type = 3;
		q.push(p);
		while (!q.empty()) {
			p = q.front();
			int dx = p.x;
			int dy = p.y;
			int type = p.type;
			q.pop();
			if (m[dy][dx] == 0) {
				if (type == 1) {
					p.x = dx;
					p.y = dy + 1;
					p.type = 1;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 2) {
					p.x = dx;
					p.y = dy - 1;
					p.type = 2;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 3) {
					p.x = dx + 1;
					p.y = dy;
					p.type = 3;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 4) {
					p.x = dx - 1;
					p.y = dy;
					p.type = 4;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
			}
			else if (m[dy][dx] == 1) { //1
				if (v[dy][dx] == 0) {
					ans++;
					v[dy][dx] = 1;
				}
				if (type == 1) {
					p.x = dx - 1;
					p.y = dy;
					p.type = 4;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 2) {
					p.x = dx + 1;
					p.y = dy;
					p.type = 3;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 3) {
					p.x = dx;
					p.y = dy - 1;
					p.type = 2;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 4) {
					p.x = dx;
					p.y = dy + 1;
					p.type = 1;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
			}
			else if (m[dy][dx] == 2) { //2
				if (v[dy][dx] == 0) {
					ans++;
					v[dy][dx] = 1;
				}
				if (type == 1) {
					p.x = dx +1;
					p.y = dy;
					p.type = 3;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 2) {
					p.x = dx - 1;
					p.y = dy;
					p.type = 4;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 3) {
					p.x = dx;
					p.y = dy + 1;
					p.type = 1;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
				else if (type == 4) {
					p.x = dx;
					p.y = dy - 1;
					p.type = 2;
					if (!range(p.y, p.x))
						break;
					q.push(p);
				}
			}
		}
		init(N);
		// �� �κп��� ������ ����Ͻʽÿ�.
		printf("Case #%d\n", test_case);	// cout ��� ����
		printf("%d\n", ans);
	}
	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}