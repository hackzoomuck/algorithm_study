//문자열 폭발
#include <iostream>
#include <string>
using namespace std;

int main() {
	string input_s, bomb;
	cin >> input_s >> bomb;
	//폭탄이 적용되는 string

	char result[1000000] = {};
	int index = 0;
	int bomb_end_index = bomb.size() - 1;

	for (int i = 0; i < input_s.size(); i++) { //고려해야할 점은 폭탄이 터지고 나서 변경된 string의 index로 봐야한다는것.
		result[index] = input_s[i];
		bool check = false;
		if (result[index] == bomb[bomb_end_index]) {
			int match_start_index = index - bomb_end_index;
			int bomi = bomb_end_index;
			//폭탄의 맨 뒷글자와 같으면 비교후 펑

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
