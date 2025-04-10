#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 987654321;
int n, population[11], minPopulation= MAX;
vector<vector<int>> adj;

int calculateDiff(vector<bool> selected) {
	int zoneA = 0, zoneB = 0;
	for (int i = 0; i < n; ++i) {
		if (selected[i])
			zoneA += population[i];
		else
			zoneB += population[i];
	}

	return abs(zoneA - zoneB);
}

bool isConnected(vector<bool> selected, bool zone) {
	//연결되었나 확인
	queue<int> q;
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (selected[i] == zone) {
			q.push(i);
			visited[i] = true;
			break;
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < adj[cur].size(); ++i) {
			int next = adj[cur][i];
			if (selected[next] == zone && !visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if ((selected[i] == zone) != visited[i])
			return false;
	}
	return true;
}

void findMinPopoulationDiff() {
	//구역 나누는 모든 조합 탐색
	for (int bit = 0; bit < (1 << n); ++bit) {
		vector<bool> selected(n, false);
		for (int j = 0; j < n; ++j) {
			if (bit & (1 << j)) {
				selected[j] = true;
			}
		}
		//나눈 구역이 연결되어 있다면 인구수 비교
		if (isConnected(selected, true) && isConnected(selected, false)) {
			minPopulation = min(minPopulation, calculateDiff(selected));
		}
	}
}

int main()
{
	cin >> n;
	adj.assign(n, vector<int>(0));
	for (int i = 0; i < n; ++i) {
		cin >> population[i];
	}
	for (int i = 0; i < n; ++i) {
		int zoneNum;
		cin >> zoneNum;
		for (int j = 0; j < zoneNum; ++j) {
			int connectedZone;
			cin >> connectedZone;
			adj[i].push_back(connectedZone-1);
		}
	}

	findMinPopoulationDiff();

	if (minPopulation == MAX)
		minPopulation = -1;
	cout << minPopulation << "\n";
	return 0;
}