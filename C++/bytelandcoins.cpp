// Bytelandian gold coins: Pranshu Gupta
// https://www.codechef.com/problems/COINS

#include <iostream>
using namespace std;

int convert (int n) {
	if (n/2 + n/3 + n/4 >= n) {
		return convert(n/2) + convert(n/3) + convert(n/4);
	} else {
		return n;
	}
}

int main() {
	int n, a, b, c, f;
	for (int i = 0; i < 10; ++i) {
		cin >> n;
		f = convert(n);
		cout << f << "\n";
	}
	return 0;
}