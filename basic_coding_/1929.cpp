//소수 구하기
#include <iostream>
using namespace std;
bool arr[1000001] = { 0, };
void aera() {
	arr[1] = 1;
	for (int i = 2; i*i < 1000001; i++) {
		for (int j = i * 2; j <= 1000001; j += i) {
			arr[j] = 1;
		}
	}
}
int main() {
	aera();
	int a, b;
	cin >> a >> b;
	for (int i = a; i <= b; i++) {
		if (arr[i] == 0) cout << i << "\n";
	}
	system("pause");
	return 0;
}