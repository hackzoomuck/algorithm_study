//���ڿ� ����
#include <iostream>
#include <string>
using namespace std;

int main() {
	string input_s, bomb;
	cin >> input_s >> bomb;
	//��ź�� ����Ǵ� string

	char result[1000000] = {};
	int index = 0;
	int bomb_end_index = bomb.size() - 1;

	for (int i = 0; i < input_s.size(); i++) { //����ؾ��� ���� ��ź�� ������ ���� ����� string�� index�� �����Ѵٴ°�.
		result[index] = input_s[i];
		bool check = false;
		if (result[index] == bomb[bomb_end_index]) {
			int match_start_index = index - bomb_end_index;
			int bomi = bomb_end_index;
			//��ź�� �� �ޱ��ڿ� ������ ���� ��

			for (int k = index; k >= match_start_index; k--) {
				if (result[k] == bomb[bomi--]) {
					check = true;
				}
				else {
					check = false;
					break;
				}
			}
		}
		if (check) {
			index -= bomb_end_index;
			continue;
		}
		index++;
	}
	if (index == 0) {
		cout << "FRULA\n";
		return 0;
	}
	for (int l = 0; l <= index-1; l++) {
		cout << result[l];
	}

	system("pause");
	return 0;
}
