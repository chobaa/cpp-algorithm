#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

int map[101][101] = { 0, };

int main()
{
	queue<pair<int, int>> qSnake;
	queue<pair<int, char>> qDir;

	int N, K;
	cin >> N;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int input_x, input_y;
		cin >> input_x >> input_y;
		map[input_x][input_y] = 1;
	}

	int L;
	cin >> L;

	for (int i = 0; i < L; i++)
	{
		int time;
		char dir;

		cin >> time >> dir;

		qDir.push(make_pair(time, dir));
	}

	int x = 1;
	int y = 2;
	int nCurDir = 1; //0: 아래 1: 오른쪽 2: 위 3: 왼쪽
	int cnt = 1;

	int dirX[4] = { 1, 0, -1, 0 };
	int dirY[4] = { 0, 1, 0, -1 };

	qSnake.push(make_pair(1, 1));	//초기 뱀 모양
	map[1][1] = 2;

	while (1)
	{
		if (x > N || y > N || x < 1 || y < 1)
			break;

		if (map[x][y] == 2)
			break;

		if (!qDir.empty())
		{
			if (cnt == qDir.front().first)
			{
				if (qDir.front().second == 'L') //왼쪽으로 회전
					nCurDir = (nCurDir + 1) % 4;
				else if (qDir.front().second == 'D') //오른쪽으로 회전
					nCurDir = (nCurDir + 3) % 4;

				qDir.pop();
			}
		}

		if (map[x][y] == 0)
		{
			qSnake.push(make_pair(x, y));
			map[qSnake.front().first][qSnake.front().second] = 0;
			qSnake.pop();
		}

		else if (map[x][y] == 1)
		{
			qSnake.push(make_pair(x, y));
		}

		map[x][y] = 2;

		x = x + dirX[nCurDir];
		y = y + dirY[nCurDir];

		cnt++;
	}
	
	cout << cnt;

	return 0;
}