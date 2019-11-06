//14888 연산자 끼워넣기
//16:25-
#include <iostream>
using namespace std;

int number_arr[101] = { 0, };
int oper[4] = { 0, };
int fun_min = 1000000000;
int fun_max = -1000000000;
int n, input;

void go(int index, int total, int plus, int minus, int mul, int div) {
	//1.불가능
	if (plus + minus + mul + div < 0) return;

	//2.정답
	if (plus + minus + mul + div == 0) {
		if (fun_min > total) fun_min = total;
		if (fun_max < total)fun_max = total;
		return;
	}

	//3.다음단계
	for (int i = 0; i < 4; i++) {
		if (i == 0 && plus>0) {
			go(index + 1, total + number_arr[index + 1], plus - 1, minus, mul, div);
		}
		if (i == 1 && minus>0) {
			go(index + 1, total - number_arr[index + 1], plus, minus - 1, mul, div);
		}
		if (i == 2 && mul>0) {
			go(index + 1, total * number_arr[index + 1], plus , minus, mul - 1, div);
		}
		if (i == 3 && div>0) {
			go(index + 1, total / number_arr[index + 1], plus , minus, mul, div - 1);
		}
	}

}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		number_arr[i] = input;
	}
	for (int i = 0; i < 4; i++) {
		cin >> input;
		oper[i] = input;
	}

	go(0, number_arr[0],oper[0],oper[1],oper[2],oper[3]);
	cout << fun_max << "\n" << fun_min;
	return 0;
}