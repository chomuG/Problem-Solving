#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int n, small, big, dx[] = { -1, 1, 0, 0 }, dy[] = {0, 0, -1, 1};
vector<vector<int>> grid;
vector<vector<bool>> visited;

bool isOutRange(int r, int c, int nr, int nc) {
	if (nr < 0 || nr >= n || nc < 0 || nc >= n)
		return true;
	int diff = abs(grid[r][c] - grid[nr][nc]);
	
	return (diff<small || diff>big || visited[nr][nc]);
}


bool canOpenBound(pair<int, int> country) {
	int cnt = 0, sum = 0;
	queue<pair<int,int>> q, pos;
	q.push(country);
	visited[country.first][country.second] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		int r = cur.first, c = cur.second;
		pos.push({r, c});
		sum += grid[r][c];
		cnt++;
		
		for (int i = 0; i < 4; ++i) {
			int nr=r+dx[i], nc=c+dy[i];
			if (!isOutRange(r, c, nr, nc)) {
				q.push({ nr, nc });
				visited[nr][nc] = true; //중복 추가 방지
			}
		}
	}
	if (cnt == 1)
		return false;
	
	int avg = sum / cnt;
	while (!pos.empty()) {
		pair<int, int> cur = pos.front();
		pos.pop();
		int r = cur.first, c = cur.second;
		grid[r][c] = avg;
	}

	return true;
}


int main() {
	int cnt = 0;
	cin >> n >> small >> big;
	grid.assign(n, vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> grid[i][j];
		}
	}

	bool isOpen = true;
	while (isOpen) {
		visited.assign(n, vector<bool>(n, false));
		isOpen = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!visited[i][j] && canOpenBound({ i, j }))
					isOpen = true;
			}
		}

		if (isOpen)
			cnt++;
	}

	cout << cnt << endl;
}