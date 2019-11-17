//9:40-10:17
//1부터 N까지 자연수 중에서 M개를 고른 수열
//같은 수를 여러 번 골라도 된다.
#include <iostream>
using namespace std;

int arr[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int j = 0; j < m; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[index] = i;
		go(index + 1, n, m);
	}
	return;
}


int main() {
	int input_n, input_m;
	cin >> input_n >> input_m;
	go(0, input_n, input_m);
	system("pause");
	return 0;
}