#include <iostream>
using namespace std;


//int doit(int _do_it,int _cnt,int _sum_count) {
//	if (_do_it > _sum_count) return 0;
//	if (_do_it == _sum_count) return 1;
//	for (int i = 1; i <= 3; i++) {
//		_cnt += doit(_do_it + i, _cnt + 1, _sum_count);
//	}
//	return _cnt;
//}

int go(int count, int sum, int goal) {
	if (sum > goal) return 0;
	if (sum == goal) return 1;
	int now = 0;
	for (int i = 1; i <= 3; i++) {
		now += go(count + 1, sum + i, goal);
	}
	return now;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n = 0;
	int num;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int input_count = 0;
		int input_sum = 0;
		cin >> num;
		cout<< go(input_count,input_sum, num)<<"\n";
	}
	system("pause");
	return 0;
}