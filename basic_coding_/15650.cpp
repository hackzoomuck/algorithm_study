//15650 N과 M(2)
//n과 m(1)에서
#include <iostream>
using namespace std;

bool check[10];
int arr[10] = { 0, };

void go(int index, int n,int m) {
	if (index == m) {
		for (int j = 0; j < m-1; j++) {
			if (arr[j] > arr[j + 1]) {
				return;
			}
		}
		
		for (int k = 0; k < m; k++) {
			cout << arr[k] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true;
		arr[index] = i;
		go(index + 1, n, m);
		check[i] = false;
	}
}

int main() {
	int input_n, input_m;
	cin >> input_n >> input_m;
	go(0, input_n, input_m);
	system("pause");
	return 0;
}
