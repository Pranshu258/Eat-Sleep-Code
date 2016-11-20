// CEIL A B: Pranshu Gupta
// https://www.codechef.com/problems/CIELAB
#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a;
	cin >> b;
	c = a - b;
	if (c % 10 < 9)
		c = c + 1;
	else 
		c = c - 1;
	cout << c;
	return 0;
}