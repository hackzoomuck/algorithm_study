//11:12
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int input_arr[10];
bool check[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int j = 0; j < m-1; j++) {
			if (arr[j] > arr[j + 1]) return;
		}
		for (int j = 0; j < m; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}
	for (int k = 0; k < n; k++) {
		if (check[k])continue;
		check[k] = true;
		arr[index] = input_arr[k];
		go(index + 1, n, m);
		check[k] = false;
	}
	return;
}

int main() {
	int input_n, input_m;
	//int number;
	cin >> input_n >> input_m;
	for (int i = 0; i < input_n; i++) {
		cin >> input_arr[i];
	}
	sort(input_arr, input_arr + input_n);
	go(0, input_n, input_m);
	system("pause");
	return 0;
}