#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 987654321

using namespace std;

int n, m, a, b, k, dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };//좌, 상, 우, 하
pair<int, int> s, e;
vector<vector<int>> board, transBoard;

bool isOutOfRange(int r, int c) {
	return (r < 0 || r >= n || c < 0 || c >= m || board[r][c] == -2);
}

bool canMove(int r, int c)
{
	for (int i = r; i < r + a; ++i) {
		for (int j = c; j < c + b; ++j) {
			if (isOutOfRange(i, j))
				return false;
		}
	}
	return true;
}

void init() {
	//유닛 이동 가능 칸 확인.
	for (int i = 0; i < transBoard.size(); ++i) {
		for (int j = 0; j < transBoard[i].size(); ++j) {
			if (!canMove(i, j)) {
				transBoard[i][j] = -2;
			}
		}
	}
}

void bfs()
{
	queue<pair<int, int>> q;
	q.push(s);
	board[s.first][s.second] = 0;
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			pair<int, int> next = { cur.first + dx[i], cur.second + dy[i] };
			if (!isOutOfRange(next.first, next.second))
			{
				if (board[cur.first][cur.second] + 1 < board[next.first][next.second]) {
					board[next.first][next.second] = board[cur.first][cur.second] + 1;
					if (e == next)
						continue;
					q.push(next);
				}
			}
		}
	}
}


int main()
{
	int answer = -1;
	scanf("%d %d %d %d %d", &n, &m, &a, &b, &k);
	board.resize(n, vector<int>(m, 0));
	transBoard.resize(n - a + 1, vector<int>(m - b + 1, MAX));


	// 장애물 좌표 입력
	for (int i = 0; i < k; ++i)
	{
		int r, c;
		scanf("%d %d", &r, &c);
		board[r-1][c-1] = -2;
	}
	// 시작점, 끝점 좌표 입력
	scanf("%d %d %d %d", &s.first, &s.second, &e.first, &e.second);
	s.first--;
	s.second--;
	e.first--;
	e.second--;

	//KICK: e가 -2가 되는 경우 고려해줘야 함.
	init();
	board=transBoard;
	n = board.size();
	m = board[0].size();
	
	bfs();
	
	if (board[e.first][e.second] != MAX && board[e.first][e.second] != -2)
		answer = board[e.first][e.second];

	printf("%d", answer);
}