//소수찾기
#include <iostream>
using namespace std;
bool arr[1001] = { 0, };
int number = 0,prime_count=0;

void aera() {
	arr[1] = 1;
	//0이면 소수
	for (int i = 2; i*i < 1001; i++) {
		for (int j = i * i; j <= 1000; j += i) {
			arr[j] = 1;
		}
	}
}


int main() {
	int N = 0;
	cin >> N;
	aera();
	for (int i = 0; i < N; i++) {
		cin >> number;
		if (arr[number] == 0) prime_count++;
	}
	cout << prime_count;
	system("pause");
	return 0;
}
