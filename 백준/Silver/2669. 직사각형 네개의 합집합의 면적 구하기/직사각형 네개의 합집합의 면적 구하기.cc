#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int board[100][100];

int main() {
	int ldx, ldy, rux, ruy, cnt=0;
	for (int i = 0; i < 4; ++i) {
		cin >> ldx >> ldy >> rux >> ruy;
		for (int i = ldx; i < rux; ++i) {
			for (int j = ldy; j < ruy; ++j) {
				board[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			if (board[i][j] == 1)
				cnt++;
		}
	}


	cout << cnt << endl;
}