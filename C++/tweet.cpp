// Closing the Tweets
// https://www.codechef.com/problems/TWTCLOSE

#include <iostream>
#include <string>
using namespace std;

int main() {
	string click;
	int T, N, count = 0;
	cin >> T >> N;
	int state[T] = {0};
	for (int i = 0; i < N; i++) {
		cin >> click;
		if (click == "CLOSEALL") {
			count = 0;
			for (int j = 0; j < T; j++) {
				state[j] = 0;
			}
			cout << count << endl;
		} else {
			int t;
			cin >> t;
			if (state[t-1] == 0) {
				state[t-1] = 1;
				count += 1;
				cout << count << endl;
			} else {
				state[t-1] = 0;
				count -= 1;
				cout << count << endl;				
			}
		}
	}
	return 0;
}
