#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, cache[4001][4001], maxLength;
string s1, s2;

int findMaxLength(int idx1, int idx2) {
	if (idx1 <0 || idx2 <0) {
		return 0;
	}

	int &ret = cache[idx1][idx2];
	if (ret != -1)
		return ret;
	
	if (s1[idx1] == s2[idx2]) {
		ret = findMaxLength(idx1 - 1, idx2 - 1) + 1;
	}
	else {
		ret = 0;
	}

	return ret;
}

int main() {
	cin >> s1 >> s2;
	memset(cache, -1, sizeof(cache));
	for (int i = s1.length() - 1; i>=0; --i) {
		for (int j = s2.length() - 1; j >= 0; --j) {
			maxLength = max(maxLength,findMaxLength(i, j));
		}
	}
	

	cout << maxLength << endl;

	return 0;
}