//GCD ��
#include <iostream>
using namespace std;
int testcase = 0, n = 0, arr[102] = { 0, };

int gcd(int x, int y) {
	if (y == 0) return x;
	else {
		gcd(y, x%y);
	}
}

int main() {
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		//�Է����� �־����� ���� 1000000 ���� ����,, �ִ� 10^10�����ϱ⿡ 
		//������ Ÿ�� int -> long long���� 
		long long sum = 0;
		for (int a = 0; a < n - 1; a++) {
			for (int b = a + 1; b < n; b++) {
				sum+=gcd(arr[a], arr[b]);
			}
		}
		cout << sum << "\n";
	}
	system("pause");
	return 0;
}