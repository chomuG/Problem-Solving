#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, testCase;
vector<vector<int>> bigAdj, smallAdj;
int inCheck[501], curVisit=1;


bool canKnow(int idx) {
	if (bigAdj[idx].size() + smallAdj[idx].size() == n - 1)
		return true;

	int cnt = 1;
	queue<int> bigQ, smallQ;
	bigQ.push(idx);
	curVisit++;
	inCheck[idx] = curVisit;

	//big check
	while (!bigQ.empty()) {
		int cur = bigQ.front();
		bigQ.pop();
		for (int i = 0; i < bigAdj[cur].size(); ++i) {
			int conn = bigAdj[cur][i];
			if (inCheck[conn] != curVisit) {
				inCheck[conn] = curVisit;
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
			if (inCheck[conn] != curVisit) {
				inCheck[conn] = curVisit;
				smallQ.push(conn);
				cnt++;
			}
		}
	}

	return cnt == n;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> testCase;

	for (int tc = 1; tc <= testCase; ++tc) {
		int answer = 0;
		cin >> n >> m;
		bigAdj.assign(n, vector<int>(0));
		smallAdj.assign(n, vector<int>(0));

		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			bigAdj[a - 1].push_back(b - 1);
			smallAdj[b - 1].push_back(a - 1);
		}

		for (int i = 0; i < n; ++i) {
			if (canKnow(i))
				answer++;
		}

		cout <<"#"<<tc<<" "<< answer << endl;
	}


	return 0;
}