#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int n, cntO, cntX, cntEmpty ,board[3][3];
map<char, int> toNum = { {'O', 2}, {'X', 1}, {'.', 0} };


void countBoard() {
	cntO = cntX = cntEmpty = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (board[i][j] == 0)
				cntEmpty++;
			else if (board[i][j] == 1)
				cntX++;
			else
				cntO++;
		}
	}
}

bool checkWin() {
	//X, O 라인 완성 갯수
	int lineO = 0, lineX = 0;
	// 행 검사
	for (int i = 0; i < 3; ++i) {
		// 전부 X(=1)인지 확인
		if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1) {
			lineX++;
		}
		// 전부 O(=2)인지 확인
		if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2) {
			lineO++;
		}
	}

	// 열 검사
	for (int j = 0; j < 3; ++j) {
		if (board[0][j] == 1 && board[1][j] == 1 && board[2][j] == 1) {
			lineX++;
		}
		if (board[0][j] == 2 && board[1][j] == 2 && board[2][j] == 2) {
			lineO++;
		}
	}

	// 대각선 검사
	// 왼쪽 위 -> 오른쪽 아래
	if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1) {
		lineX++;
	}
	if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2) {
		lineO++;
	}

	// 오른쪽 위 -> 왼쪽 아래
	if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1) {
		lineX++;
	}
	if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2) {
		lineO++;
	}

	// x와 o가 동시에 이겼을 때
	if (lineX != 0 && lineO != 0) {
		return false;
	}
	else if (lineX != 0 && cntO == cntX) {//X가 이겼는데 O와 개수가 같을 때
		return false;
	}
	else if (lineO != 0 && cntO != cntX) {//O가 이겼는데 X와 개수가 다를 때
		return false;
	}
	else if (lineO == 0 && lineX == 0 && cntEmpty != 0) {//아무도 못이겼는데 빈칸이 있을 때
		return false;
	}
	
	return true;
}

bool isValid() {
	// cntO <= cntX 확인
	countBoard();
	if (cntX < cntO || cntO + 1< cntX)
		return false;

	//승리 라인 확인
	return checkWin();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	while (1) {
		cin >> s;
		if (s == "end")
			break;
		//보드 숫자로 저장
		for (int i = 0; i < 9; ++i) {
			board[i / 3][i % 3] = toNum[s[i]];
		}

		if (isValid())
			cout << "valid" << "\n";
		else
			cout << "invalid" << "\n";
	}

	return 0;
}
