//14501 퇴사 (브루트 포스/재귀)
//n일 동안 일을 해서 n+1일에 받을 수 있는 최대금액을 계산
//1.정답을 찾은 경우 2.불가능한 경우 3.다음경우
//13:50-15:30
#include <iostream>
using namespace std;

int n,t,p;
int ti[17] = { 0, }, pi[17] = { 0, };
int sum_max = 0;

//index:현재 날짜, sum:이익
void go(int index, int sum) {
	if (index > n) return;
	if (index == n) {
		if (sum_max < sum) {
			sum_max = sum;
		}
		return;
	}
	go(index + ti[index], sum + pi[index]);
	go(index + 1, sum);
	
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		ti[i] = t;
		pi[i] = p;
	}
	go(0, 0);
	cout << sum_max;

	return 0;
}
