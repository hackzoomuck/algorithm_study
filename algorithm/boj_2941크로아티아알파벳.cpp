//cro[]�� ũ�ξ�Ƽ�� ���ĺ����� �����ϰ�
//���ڿ��� ���ڿ� cro[]�� �ִ� ���ڿ��� ù���ڿ� ��
#include <iostream>
#include <string>
using namespace std;

string cro[8] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
string input;
bool cro_b = false;
int cnt = 0;

int main() {
	cin >> input;
	for (int i = 0; i < input.size(); i++) {
		for (int j = 0; j < 8; j++) {
			for (int k = 0; k < cro[j].size(); k++) {
				if (input[i] == cro[j][k]) {
					i++;
					if (k == cro[j].size() - 1) i--;
				}
				else {
					if (k) {
						i -= k;
					}
					break;
				}
			}
		}
		cnt++;
	}
	cout << cnt<<"\n";
	system("pause");
	return 0;
}