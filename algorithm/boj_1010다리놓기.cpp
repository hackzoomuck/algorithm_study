//조합이다, 1!에서부터 east!까지 계산 후, east!/(east-west)!west! 로 풀려했으나
//자료형의 범위를 벗어난다.
//
//#include <iostream>
//using namespace std;
//unsigned long long arr[31] = { 0, };
//
//int main() {
//	/*int n;
//	int end = 1;
//	cin >> n;
//	arr[0] = 1;
//	arr[1] = 1;
//	while (n--) {
//		int west, east;
//		cin >> west >> east;
//		for (int i = end; i < east; i++) {
//			arr[i + 1] = arr[i] * (i + 1);
//		}
//		end = east;
//		cout << arr[east] / (arr[east - west] * arr[west]) << "\n";
//	}*/
//	arr[0] = 1; arr[1] = 1;
//	for (int i = 2; i <= 30; i++) {
//		arr[i] = arr[i - 1] * i;
//	}
//	for (int i = 0; i <= 30; i++) {
//		cout << "[" << i << "] = " << arr[i] << endl;
//	}
//	system("pause");
//	return 0;
//}

#include <iostream>
using namespace std;

int arr[31][31] = { 0, };

int go(int n, int r) {
	if (r == 0 || n == r ) return 1;
	if (arr[n][r]) return arr[n][r];
	return arr[n][r] = go(n - 1, r - 1) + go(n - 1, r);
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int west, east;
		cin >> west >> east;
		cout << go(east, west) << "\n";
	}
	return 0;
}