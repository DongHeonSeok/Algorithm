// 아래 기본 제공된 코드를 수정 또는 삭제하고 본인이 코드를 사용하셔도 됩니다.
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
	/* 아래 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로 부터 읽어오겠다는 의미의 코드입니다.
	만약 본인의 PC 에서 테스트 할 때는, 입력값을 input.txt에 저장한 후 freopen 함수를 사용하면,
	그 아래에서 scanf 함수 또는 cin을 사용하여 표준입력 대신 input.txt 파일로 부터 입력값을 읽어 올 수 있습니다.
	또한, 본인 PC에서 freopen 함수를 사용하지 않고 표준입력을 사용하여 테스트하셔도 무방합니다.
	단, Codeground 시스템에서 "제출하기" 할 때에는 반드시 freopen 함수를 지우거나 주석(//) 처리 하셔야 합니다. */
	//freopen("input.txt", "r", stdin);

	setbuf(stdout, NULL);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능
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
		// 이 부분에서 정답을 출력하십시오.
		printf("Case #%d\n", test_case);	// cout 사용 가능
		printf("%d\n", ans);
	}
	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}