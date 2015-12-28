#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int i, j, n;
	cout << "Enter the length of array: ";
	cin >> n;

	int arr[n];
	vector<int> sol(n, 1);
	memset(arr, 0, n);

	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (i = 1; i < n; i++) {
		for (j = 0; j < i; j++) {
			if (arr[j] < arr[i])
				sol[i] = max(sol[j]+1, sol[i]);
		}
	}

	cout << "Longest increasing subsequence: " << *max_element(sol.begin(), sol.end()) << endl;
	return 0;
}
