#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, maxCnt, dx[] = { -1, 1, 0, 0 }, dy[] = {0, 0, -1, 1};
vector<vector<int>> grid, copyGrid;
vector<pair<int, int>> virus;

bool isOutRange(int r, int c) {
	return (r < 0 || r >= n || c < 0 || c >= m || copyGrid[r][c] == 1 || copyGrid[r][c] == 2);
}


void dfs(pair<int, int> v) {
	int r = v.first, c = v.second;
	copyGrid[r][c] = 2;

	for (int i = 0; i < 4; ++i) {
		int nr=r+dx[i], nc=c+dy[i];
		if (!isOutRange(nr, nc)) {
			dfs({nr, nc});
		}
	}
}

int getSafeCnt() {
	int cnt = 0;
	copyGrid = grid;

	for (pair<int, int> v : virus) {
		dfs(v);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (copyGrid[i][j] == 0)
				cnt++;
		}
	}

	return cnt;
}

void getMaxSafe(int curPos,int remainWall) {
	if (remainWall == 0) {
		maxCnt = max(maxCnt, getSafeCnt());
		return;
	}

	if (curPos == n * m - 1) {
		return;
	}

	for (int i = curPos+1; i < m*n; ++i) {
		int r = i / m, c = i % m;
		if (grid[r][c] == 0) {
			grid[r][c] = 1;
			getMaxSafe(i, remainWall-1);
			grid[r][c] = 0;
		}
	}
}


int main() {
	cin >> n >> m;
	grid.assign(n, vector<int>(m));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
			if (grid[i][j] == 2) {
				virus.push_back({ i, j });
			}
		}
	}
	for (int i = 0; i < m*n; ++i) {
		int r= i/m, c=i%m;
		if (grid[r][c] == 0) {
			grid[r][c] = 1;
			getMaxSafe(i, 2);
			grid[r][c] = 0;
		}
	}

	cout << maxCnt << endl;
}