//input		output(����)
//1S2D*3T	37	(11 * 2 + 22 * 2 + 33)
//1D2S#10S	9	(12 + 21 * (-1) + 101)

#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

//������ ����� �б� *�� ���� �ٷ� ���� ������ 2����=>vector����
int solution(string dartResult) {
	int answer = 0;
	int tmp = 0;
	vector<int> v;
	for (int i = 0; i < dartResult.size(); i++) {
		if (dartResult[i] == 'S') {
			v.push_back(tmp);
			continue;
		}
		if (dartResult[i] == 'D') {
			tmp = pow(tmp, 2);
			v.push_back(tmp);
			continue;
		}
		if (dartResult[i] == 'T') {
			tmp = pow(tmp, 3);
			v.push_back(tmp);
			continue;
		}
		if (dartResult[i] == '*') {
			tmp = 0;
			int num = v.size();
			if ((num - 2) >= 0) {
				v[num - 2] *= 2;
			}
			v[num - 1] *= 2;
			continue;
		}
		if (dartResult[i] == '#') {
			for (int j = 0; j < v.size(); j++) {
				v[j] *= -1;
			}
			tmp = 0;
			continue;
		}
		string num = "";
		num = dartResult[i];

		//���� Ǯ�̶�,
		//int isdigit(int c);
		//c : �˻��� ���� �Ǵ� �ƽ�Ű ��
		//��ȯ�� : ���ڰ� 0~9 ���̿� ���ϸ� true, �ƴϸ� false
		while (dartResult[i + 1] >= '0' && dartResult[i + 1] <= '9') {
			num.append(1, dartResult[i + 1]);
			i++;
		}
		tmp = stoi(num);
	}
	for (int k = 0; k < v.size(); k++) {
		answer += v[k];
	}
	cout << answer;
	return answer;
}

int main() {
	string is;
	cin >> is;
	solution(is);
	system("pause");
	return 0;
}