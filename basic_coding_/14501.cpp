//14501 ��� (���Ʈ ����/���)
//n�� ���� ���� �ؼ� n+1�Ͽ� ���� �� �ִ� �ִ�ݾ��� ���
//1.������ ã�� ��� 2.�Ұ����� ��� 3.�������
//13:50-15:30
#include <iostream>
using namespace std;

int n,t,p;
int ti[17] = { 0, }, pi[17] = { 0, };
int sum_max = 0;

//index:���� ��¥, sum:����
void go(int index, int sum) {
	if (index > n) return;
	if (index == n) {
		if (sum_max < sum) {
			sum_max = sum;
		}
		return;
	}
	go(index + ti[index], sum + pi[index]);
	go(index + 1, sum);
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		ti[i] = t;
		pi[i] = p;
	}
	go(0, 0);
	cout << sum_max;

	return 0;
}
