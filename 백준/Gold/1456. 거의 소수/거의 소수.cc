#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
long long a, b, cnt;
bool check[10000001];
long long LIMIT = (long long)1e14;

void makePrime() {
	check[0] = false;
	check[1] = false;
	long long sqrtB = sqrt(b);

	for (long long i = 2; i * i <= sqrtB; i++) {
		if (check[i]) {
			for (long long j = i * i; j <= sqrtB; j += i) {
				check[j] = false;
			}
		}
	}
	
	for (long long i = 2; i <= sqrtB; ++i) {
		if (check[i]) {
			long long power = i;
			while (power <= b / i) {
				power *= i;

				if (power > b) break;

				if (a <= power) {
					cnt++;
				}
			}
		}
	}
}


int main() {
	cin >> a >> b;
	for (int i = 0; i < 10000000; ++i) {
		check[i] = true;
	}
	makePrime();

	cout << cnt << endl;
	return 0;
}