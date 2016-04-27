#include <stdio.h>

int map[11][11];    // 처음 받아오는 값
int visit_a[30];    // 체크
int visit_b[30];
int Max = 0;
int chessSize;


void Black(int row, int cal, int cnt){
	if (cnt > Max)
		Max = cnt;


	if (cal > chessSize){
		row++;

		if (row % 2 == 0)
			cal = 2;
		else
			cal = 1;
	}

	if (row > chessSize){
		return;
	}

	if (visit_a[row + cal] == 0 && visit_b[10 + row - cal] == 0 && map[row][cal] == 1){
		visit_a[row + cal] = 1;
		visit_b[10 + row - cal] = 1;
		Black(row, cal + 2, cnt + 1);
		visit_a[row + cal] = 0;
		visit_b[10 + row - cal] = 0;
	}
	Black(row, cal + 2, cnt);
}

void White(int row, int cal, int cnt){
	if (cnt > Max)
		Max = cnt;


	if (cal > chessSize){
		row++;

		if (row % 2 == 0)
			cal = 1;
		else
			cal = 2;
	}

	if (row > chessSize){
		return;
	}

	if (visit_a[row + cal] == 0 && visit_b[10 + row - cal] == 0 && map[row][cal] == 1){
		visit_a[row + cal] = 1;
		visit_b[10 + row - cal] = 1;
		White(row, cal + 2, cnt + 1);
		visit_a[row + cal] = 0;
		visit_b[10 + row - cal] = 0;
	}
	White(row, cal + 2, cnt);
}

int main(void){
	int result;
	scanf("%d", &chessSize);

	for (int i = 1; i <= chessSize; i++)
		for (int j = 1; j <= chessSize; j++)
			scanf("%d", &map[i][j]);

	Black(1, 1, 0);    // 1,1 시작 에서 0번
	result = Max;
	Max = 0;

	White(1, 2, 0);
	result += Max;

	printf("%d\n", result);

	return 0;
}
