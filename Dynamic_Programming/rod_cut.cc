#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cout << "Enter the legnth of rod: ";
	cin >> n;
	
	int sol[n+1];
	int val[n+1];
	int i, j;
	int maxv;
	memset(sol, 0, n);
	memset(val, 0, n);

	for (i = 1; i <= n; i++) {
		cin >> val[i];
	}

	sol[1] = val[1];

	for (i = 2; i <= n; i++) {
		maxv = -1;

		for (j = 1; j < i; j++) {
			maxv = max(maxv, (sol[i-j]+sol[j]));
		}

		sol[i] = max(maxv, val[i]);
	}

	cout << "Max value = " << sol[n] << endl;

	return 0;
}
