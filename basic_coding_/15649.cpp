//15:40-15:56
//N�� M(1)
//1-N���� �ڿ��� �߿��� �ߺ����� M�� �̴� ����
//return �Ǿ��� ���� index���� ���� ���� �߸�����
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