#include <iostream>
using namespace std;

int arr[91][2] = { 0, };

int go(int n) {
	arr[1][0] = 0;
	arr[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}
	return arr[n][0] + arr[n][1];
}

int main() {
	int n;
	cin >> n;
	cout<<go(n)<<"\n";
	system("pause");
	return 0;
}


