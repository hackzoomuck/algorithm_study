//10:20-10:34
//1���� N���� �ڿ��� �߿��� M���� �� ����
//���� ���� ���� �� ��� �ȴ�.
//�� ������ �񳻸������̾�� �Ѵ�.
//���̰� K�� ���� A�� A1 �� A2 �� ... �� AK - 1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.
#include <iostream>

using namespace std;

int arr[10];

void go(int index, int n, int m) {
	if (index == m) {
		for (int j = 0; j < m-1; j++) {
			if (arr[j] > arr[j + 1]) return;
		}
		for (int k = 0; k < m; k++) {
			cout << arr[k] << " ";
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