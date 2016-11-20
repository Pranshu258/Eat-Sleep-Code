// Implementation of Prime Seive
// Author: Pranshu Gupta

#include <iostream>
#include <list>
using namespace std;

list<int> primeSeive (int n) {
	list<int> primes;
	int composites[n+1] = {0};
	composites[0] = 1;
	composites[1] = 1;
	for (int i = 2; i < n+1; i++) {
		if (composites[i] != 1) {
			for (int j = i + 1; j < n + 1; j++) {
				if (j % i == 0) {
					composites[j] = 1;
				}
			}
			// Add the number to the list of primes here
			primes.push_back(i);
		}
		
		
	}
	return primes;
}

int main () {
	int n;
	cin >> n;
	list<int> primes = primeSeive(n);
	list<int>::iterator i;
	for(i = primes.begin(); i != primes.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
	return 0;
}

