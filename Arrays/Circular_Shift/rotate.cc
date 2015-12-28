#include <iostream>

using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(arr)/sizeof(arr[0]);
	int d = 3;
	int i, j, k, temp;

	for (i = 0; i < gcd(d, n); i++) {
		temp = arr[i];
		j = i;
		while(1) {
			k = (j + d)%n;
			if (k == i)
				break;
			arr[j] = arr[k];
			j = k;
		}
		arr[j] = temp;
	}
	for(i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
