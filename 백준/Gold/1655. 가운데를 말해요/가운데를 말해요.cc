#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int n;

int main() {
	ios_base::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	priority_queue<int> left;
	priority_queue<int, vector<int>,greater<>> right;
	int num, ans;
	for (int i = 0; i < n; ++i) {
		cin >> num;
		if (left.empty() || num<=left.top()) {
			left.push(num);
		}
		else{
			right.push(num);
		}

		if (left.size() > right.size() + 1) {
			right.push(left.top());
			left.pop();
		}
		else if (right.size() > left.size() + 1) {
			left.push(right.top());
			right.pop();
		}

		if (right.size() == left.size()) {
			ans = min(left.top(), right.top());
		}
		else if(left.size()< right.size()){
			ans = right.top();
		}
		else {
			ans = left.top();
		}

		cout << ans << "\n";
	}


	return 0;
}