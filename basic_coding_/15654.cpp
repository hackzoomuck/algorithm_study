//11:05-11:12
//N개의 자연수와 자연수 M이 주어졌을 때, 
//아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
//N개의 자연수는 모두 다른 수이다.
//N개의 자연수 중에서 M개를 고른 수열
//배열에 넣어서 그 인덱스로 하면 됨.
#include <iostream>
#include <algorithm>
using namespace std;

int arr[10];
int input_arr[10];
bool check[10];

void go(int index, int n, int m) {
	if (index == m) {
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