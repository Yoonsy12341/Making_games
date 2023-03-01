#include <iostream>
#include <conio.h>
using namespace std;

/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 폭탄 이펙트
*/
struct _tagPoint {
	int x;
	int y;
};

//typedef : 타입을 재정의하는 기능
typedef _tagPoint	POINT;
typedef _tagPoint* PPOINT;



void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos, PPOINT pEndPos)
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;

 	strcpy_s(Maze[0],  "21100000000000000000");
	strcpy_s(Maze[1],  "00111111111000000000");
	strcpy_s(Maze[2],  "00100100011111111110");
	strcpy_s(Maze[3],  "01100100000000001000");
	strcpy_s(Maze[4],  "01000111100011111100");
	strcpy_s(Maze[5],  "01000000111110000100");
	strcpy_s(Maze[6],  "01000000010010000100");
	strcpy_s(Maze[7],  "01111000010010000110");
	strcpy_s(Maze[8],  "00010000010010000011");
	strcpy_s(Maze[9],  "00110001110010000000");
	strcpy_s(Maze[10], "00110001000010001000");
	strcpy_s(Maze[11], "00101111111011111100");
	strcpy_s(Maze[12], "00100000001000001000");
	strcpy_s(Maze[13], "11100111001111001000");
	strcpy_s(Maze[14], "10011101100000001110");
	strcpy_s(Maze[15], "11110000100000000100");
	strcpy_s(Maze[16], "00110000100011111100");
	strcpy_s(Maze[17], "00100000101010001000");
	strcpy_s(Maze[18], "00111100011010001100");
	strcpy_s(Maze[19], "00000111110010000113");
}

void Output(char Maze[21][21], PPOINT pPlayerPos) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 20; ++j) {

			if (Maze[i][j] == '4')
				cout << "＠";
			else if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "★";
			else if (Maze[i][j] == '0')
				cout << "■";
			else if (Maze[i][j] == '1')
				cout << "  ";
			else if (Maze[i][j] == '2')
				cout << "◎";
			else if (Maze[i][j] == '3')
				cout << "§";
				

		}
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		//벽인지 체크
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0'&&
			Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
		{
			--pPlayerPos->y;
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 20)
	{
		//벽인지 체크
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0'&&
			Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
		{
			++pPlayerPos->y;
		}
	}
}
void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 >= 0)
	{
		//벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0'&&
			Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
		{
			--pPlayerPos->x;
		}
	}
}
void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20)
	{
		//벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0'&&
			Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
		{
			++pPlayerPos->x;
		}
	}
}



void MovePlayer(char Maze[21][21], PPOINT pPlayerPos,char cInput) {

	switch (cInput) {
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	case 't':
	case 'T':
		CreateBomb(Maze, pPlayerPos, );
		break;
	case 'u':
	case 'U':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

void CreateBomb(char Maze[21][21], const PPOINT pPlayer,
	PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	for (int i = 0; i < *pBombCount; ++i) 
	{
		if (pPlayer->x == pBombArr[i].x &&
			pPlayer->y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = *pPlayer;
	++(*pBombCount);

	Maze[pPlayer->y][pPlayer->x] = '4';

}

void Fire(char Maze[21][21]) {}

int main() {

	// 20 x 20 미로를 만들어준다.
	char strMaze[21][21];

	POINT tPlayerPos;
	POINT tStartPos;
	POINT tEndPos;

	int iBombCount = 5;
	int iAddBomb = 0;

	POINT tBombPos[5];

	//미로 설정
	SetMaze(strMaze,&tPlayerPos, &tStartPos, &tEndPos);

	
	while (true) {
		system("cls");
		//미로 출력
		Output(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y) {
			cout << "도착했습니다." << endl;
			break;
		}

		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 Q : 종료";
		char	cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 't' || cInput == 'T')
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		else
			MovePlayer(strMaze, &tPlayerPos, cInput);
	}
	return 0;
}


