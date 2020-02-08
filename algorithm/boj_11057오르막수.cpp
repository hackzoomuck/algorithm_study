#include <iostream>
using namespace std;

int arr[1001][10] = { 0, };

int main() {
	int n, res = 0;
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		arr[1][i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] = (arr[i][j] + arr[i - 1][k]) % 10007;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		res += arr[n][i];
	}
	cout << res << "\n";
	system("pause");
	return 0;
}