//cro[]에 크로아티아 알파벳변경 저장하고
//문자열의 문자와 cro[]에 있는 문자열의 첫문자와 비교
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