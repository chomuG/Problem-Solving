#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, dx[] = { 0, 1, 1 }, dy[] = { 1, 0, 1 };//가로 세로 대각
vector<vector<int>> grid, checkArea = { {0, 2},{1, 2},{0, 1, 2} };

bool isOutRange(int r, int c, int shape) {
	if (r<1 || r>n || c<1 || c>n || grid[r][c] == 1)
		return true;

	if (shape == 2) {
		return (grid[r - 1][c] == 1 || grid[r][c - 1] == 1);
	}

	return false;
}


int countMethod(int r, int c, int shape) {//shape 가로 세로 대각 (0, 1, 2)
	if (r == n && c == n) {
		return 1;
	}

	int ret = 0;

	for (int i = 0; i < checkArea[shape].size(); ++i) {
		int nr, nc, nShape;
		nr = r + dx[checkArea[shape][i]];
		nc = c + dy[checkArea[shape][i]];
		nShape = checkArea[shape][i];

		if(!isOutRange(nr, nc, nShape))
			ret += countMethod(nr, nc, nShape);
	}

	return ret;
}

int main() {
	cin >> n;
	grid.assign(n+1, vector<int>(n+1));

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> grid[i][j];
		}
	}

	cout << countMethod(1, 2, 0) << endl;

	return 0;
}
