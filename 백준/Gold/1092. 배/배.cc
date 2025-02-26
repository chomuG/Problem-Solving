#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
list<int> crain, box;

int getMinTime() {
	int time = 0;

	while (!box.empty()) {
		time++;
		if (crain.front() < box.front()) {
			return -1;
		}

		auto crane_it = crain.begin();
		auto box_it = box.begin();

		while (crane_it != crain.end() && box_it != box.end()) {
			if (*box_it <= *crane_it) {
				box_it = box.erase(box_it);
				++crane_it;
			}
			else {
				++box_it;
			}
		}
	}

	return time;
}

int main() {
	cin >> n;
	crain.resize(n);
	for (auto i = crain.begin(); i != crain.end() ; ++i)
		cin >> *i;
	cin >> m;
	box.resize(m);
	for (auto i = box.begin(); i != box.end(); ++i)
		cin >> *i;

	crain.sort(greater<>());
	box.sort(greater<>());
	

	cout << getMinTime() << endl;


	return 0;
}