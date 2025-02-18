#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m;
vector<vector<int>> bigAdj, smallAdj;

bool canKnow(int idx) {
	if (bigAdj[idx].size() + smallAdj[idx].size() == n - 1)
		return true;
	int cnt = 1;
	queue<int> bigQ, smallQ;
	vector<bool> inCheck(n, false);
	bigQ.push(idx);
	inCheck[idx] = true;

	//big check
	while (!bigQ.empty()) {
		int cur = bigQ.front();
		bigQ.pop();
		for (int i = 0; i < bigAdj[cur].size(); ++i) {
			int conn = bigAdj[cur][i];
			if (!inCheck[conn]) {
				inCheck[conn] = true;
				bigQ.push(conn);
				cnt++;
			}
		}
		
	}

	smallQ.push(idx);
	//small check
	
	while (!smallQ.empty()) {
		int cur = smallQ.front();
		smallQ.pop();
		for (int i = 0; i < smallAdj[cur].size(); ++i) {
			int conn = smallAdj[cur][i];
			if (!inCheck[conn]) {
				inCheck[conn] = true;
				smallQ.push(conn);
				cnt++;
			}
		}
	}
	if (cnt == n)
		return true;
	return false;
}


int main() {
	int answer = 0;
	cin >> n >> m;
	bigAdj.resize(n, vector<int>(0));
	smallAdj.resize(n, vector<int>(0));

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		bigAdj[a-1].push_back(b-1);
		smallAdj[b-1].push_back(a-1);
	}

	for (int i = 0; i < n; ++i) {
		if (canKnow(i))
			answer++;
	}

	cout << answer << endl;
	return 0;
}