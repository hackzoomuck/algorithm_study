#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v_oper;
vector<int> v_num;
int input_max = -999999999;
int input_min = 999999999;

void go(int total, int index, int plus, int minus, int mul, int div) {
	
	if (index == v_num.size()) {
		if (total > input_max) input_max = total;
		if (total < input_min) input_min = total;
		return;
	}
	if (plus > 0) go(total + v_num[index], index + 1, plus - 1, minus, mul, div);
	if (minus > 0) go(total - v_num[index], index + 1, plus, minus - 1, mul, div);
	if (mul > 0) go(total * v_num[index], index + 1, plus, minus, mul - 1, div);
	if (div > 0) go(total / v_num[index], index + 1, plus, minus, mul, div - 1);
}

int main() {
	int num;
	int input;
	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> input;
		v_num.push_back(input);
	}

	int a = 0;
	for (int i = 0; i < 4; i++) {
		cin >> input;
		v_oper.push_back(input);
		}
	go(v_num[0],1,v_oper[0],v_oper[1],v_oper[2],v_oper[3]);
	//do {
	//	int sum = v_num[0];
	//	for (int i = 0; i < num-1; i++) {
	//		if (v_oper[i] == 0)  sum = sum + v_num[i + 1];
	//		if (v_oper[i] == 1)  sum = sum - v_num[i + 1];
	//		if (v_oper[i] == 2)  sum = sum * v_num[i + 1];
	//		if (v_oper[i] == 3)  sum = sum / v_num[i + 1];
	//	}
	//	if (input_max < sum)input_max = sum;
	//	if (input_min > sum)input_min = sum;
	//} while (next_permutation(v_oper.begin(), v_oper.end()));

	cout << input_max << "\n" << input_min << "\n";
	system("pause");
	return 0;
}