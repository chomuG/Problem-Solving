#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> stairs, cache;

int main() {
	cin >> n;
	stairs.assign(n, 0);
	cache.assign(n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> stairs[i];
	}
	cache[0] = stairs[0];
	cache[1] = stairs[0] + stairs[1];
	cache[2] = max({stairs[2] + cache[0],stairs[2]+stairs[1]});

	for (int i = 3; i < n; ++i) {
		cache[i] = max(stairs[i]+stairs[i-1]+cache[i-3], stairs[i]+ cache[i-2]);
	}

	cout << cache[n - 1]<<"\n";

	return 0;
}