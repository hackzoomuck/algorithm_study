//15:40-15:56
//N과 M(1)
//1-N까지 자연수 중에서 중복없이 M를 뽑는 수열
//return 되었을 때에 index값에 대한 이해 잘못했음
#include <iostream>

using namespace std;

bool check[10];
int arr[10] = { 0, };

void go(int index, int n, int m) {
	if (index == m) {
		for (int i = 0; i < m; i++) {
		 cout << arr[i]<<" ";
		}
		cout << "\n";
		return;
	}
	for (int j = 1; j <= n; j++) {
		if (check[j]) continue;
		check[j] = true;
		arr[index] = j;
		go(index + 1, n, m);
		check[j] = false;
	}
}

int main() {
	int input_n, input_m;
	cin >> input_n >> input_m;
	go(0, input_n, input_m);
	system("pause");
	return 0;
}