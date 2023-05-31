#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define INDEX(X) X-1

#define LEFT 1
#define RIGHT 2

int block[9][4][4][4] = {
	{ // 네모
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		}
	},
	{ //일자
		{
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0},
			{0,0,0,0}
		},
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{
			{0,0,0,0},
			{0,0,0,0},
			{1,1,1,1},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0},
			{0,1,0,0}
		}
	},
	{ //T자모양
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,1},
			{0,0,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,0,1,0}
		}
	},
	{ //지그재그L
		{
			{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,1},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,1,0,0}
		}
	},
	{ //지그재그R
		{
			{0,0,0,0},
			{0,0,1,1},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,1,0,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		}
	},
	{ //L자모양L
		{
			{0,0,1,0},
			{0,0,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{0,1,1,1},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,1,0,0},
			{0,1,0,0}
		},
		{
			{0,0,0,0},
			{1,1,1,0},
			{0,0,1,0},
			{0,0,0,0}
		}
	},
	{ //L자모양R
		{
			{0,1,0,0},
			{0,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,1},
			{0,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,0},
			{0,0,1,0},
			{0,0,1,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		}
	},
	{ //H모양
		{
			{0,1,0,1},
			{0,1,1,1},
			{0,1,0,1},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,1,1},
			{0,0,1,0},
			{0,1,1,1}
		},
		{
			{0,0,0,0},
			{1,0,1,0},
			{1,1,1,0},
			{1,0,1,0}
		},
		{
			{1,1,1,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
		}
	},
	{ //H모양
		{
			{1,0,0,1},
			{0,0,0,0},
			{0,0,0,0},
			{1,0,0,1}
		},
		{
			{1,0,0,1},
			{0,0,0,0},
			{0,0,0,0},
			{1,0,0,1}
		},
		{
			{1,0,0,1},
			{0,0,0,0},
			{0,0,0,0},
			{1,0,0,1}
		},
		{
			{1,0,0,1},
			{0,0,0,0},
			{0,0,0,0},
			{1,0,0,1}
		}
	}
};

int board[15 + 1][10 + 2] = {
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1}
};

int block_x, block_y;
int random_shape =0;
int rotate = 0;

void gotoxy(int x, int y) {
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int CrashEvent();
int WallCrashEvent(int);
void SetMouseCurSorInv();
void AddBlock();
void DrawBoard();
void DropBlock();
void CheckLine();


int main(void) {
	int dropbasetime = (int)time(NULL);
	int droptime = 0;
	double delaytime = (double)time(NULL);

	DrawBoard();

	SetMouseCurSorInv();
	AddBlock();
	while (1) {
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) { //왼쪽
			if (WallCrashEvent(LEFT) == 0) {
				block_x--;
				DrawBoard();
			}
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { //오른쪽
			if (WallCrashEvent(RIGHT) == 0) {
				block_x++;
				DrawBoard();
			}
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) { //아래
			if (CrashEvent() == 0) {
				block_y++;
				DrawBoard();
			}
		}
		if (GetAsyncKeyState(0x52) & 0x8000) { //회전
			if (WallCrashEvent(RIGHT) == 0) {
				if (WallCrashEvent(LEFT) == 0) {
					if (CrashEvent() == 0) {
						otate = (rotate + 1) % 4;
						DrawBoard();
						delaytime = (double)time(NULL);
					}
				}
			
		}


		droptime = (int)time(NULL) - dropbasetime;
		if (droptime >= 1) {
			DropBlock();
			dropbasetime = (int)time(NULL);
			DrawBoard();
		}
	}
}


int CrashEvent() {
	for (int pos_y = 0; pos_y < 4; pos_y++) {
		for (int pos_x = 0; pos_x < 4; pos_x++) {
			if (block[random_shape][rotate][pos_y][pos_x] == 1) {
				if (board[block_y + pos_y + 1][block_x + pos_x] == 1) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int WallCrashEvent(int direction) {
	switch (direction) {
	case LEFT:
		for (int pos_y = 0; pos_y < 4; pos_y++) {
			for (int pos_x = 0; pos_x < 4; pos_x++) {
				if (block[random_shape][rotate][pos_y][pos_x] == 1) {
					if (board[block_y + pos_y][block_x + pos_x - 1] == 1) {
						return 1;
					}
				}
			}
		}
		break;
	case RIGHT:
		for (int pos_y = 0; pos_y < 4; pos_y++) {
			for (int pos_x = 0; pos_x < 4; pos_x++) {
				if (block[random_shape][rotate][pos_y][pos_x] == 1) {
					if (board[block_y + pos_y][block_x + pos_x + 1] == 1) {
						return 1;
					}
				}
			}
		}
		break;
	}
	return 0;
}

void SetMouseCurSorInv() {
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void AddBlock() {
	block_x = INDEX(5);
	block_y = INDEX(1);
	srand((int)time(NULL));
	random_shape = rand() % 7;
}

void DrawBoard() {
	system("cls");
	for (int pos_y = 0; pos_y < 16; pos_y++) {
		for (int pos_x = 0; pos_x < 12; pos_x++) {
			gotoxy(6 + (pos_x * 2), 6 + pos_y);
			printf("%s", ((board[pos_y][pos_x] == 1) ? "■" : "□"));
		}
	}
	for (int pos_y = 0; pos_y < 4; pos_y++) {
		for (int pos_x = 0; pos_x < 4; pos_x++) {
			gotoxy(6 + (block_x+pos_x)*2, 6 + block_y + pos_y);
			if (block[random_shape][rotate][pos_y][pos_x] == 1) {
				printf("■");
			}
		}
	}

	gotoxy(0, 6 + 16);
}

void PlaceBlock() {
	for (int pos_y = 0; pos_y < 4; pos_y++) {
		for (int pos_x = 0; pos_x < 4; pos_x++) {
			if (block[random_shape][rotate][pos_y][pos_x] == 1) {
				board[block_y + pos_y][block_x + pos_x] = 1;
			}
		}
	}
	CheckLine();
}

void DropBlock() {
	if (CrashEvent() == 0) {
		block_y++;
	}
	else {
		PlaceBlock();
		AddBlock();
	}
}

void CheckLine() {
	int count = 0;

	for (int pos_y = 0; pos_y < 15; pos_y++) {
		for (int pos_x = 0; pos_x < 10; pos_x++) {
			if (board[pos_y][1 + pos_x] == 1) {
				count++;
			}
		}
		if (count == 10) {
			for (int pos_x = 0; pos_x < 10; pos_x++) {
				board[pos_y][1 + pos_x] = 0;
			}
			for (int vpos_y = pos_y; vpos_y > 0; vpos_y--) {
				for (int pos_x = 0; pos_x < 10; pos_x++) {
					board[vpos_y][1 + pos_x] = board[vpos_y - 1][1 + pos_x];
				}
			}
			for (int pos_x = 0; pos_x < 10; pos_x++) {
				board[0][pos_x] = 0;
			}
		}
		count = 0;
	}
}
