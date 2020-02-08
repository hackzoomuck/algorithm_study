//각 자리를 가장 큰수로 해서 업데이트
//틀림!! 1 4 2 3 1 5 -> 1 4 5 로 나옴 1 2 3 5가 답
#include <iostream>
#include <vector>
using namespace std;

int arr[1001] = { 0, };
vector<int> v;

int main() {
	int n;
	cin >> n;
	v.resize(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int current_max = 0;
	int pre_max = 0;
	int cnt_max = 0;
	int max_num = 0;
	for (int i = 1; i <= n; i++) {
		current_max = arr[i];
		pre_max = 0;
		cnt_max = 0;
		for (int j = 1; j <= i; j++) {
			if (current_max >= arr[j] && pre_max < arr[j]) {
				pre_max = arr[j];
				cnt_max++;
				v[j] = cnt_max;
			}
			if (max_num < cnt_max)max_num = cnt_max;
		}
	}
	cout << max_num << "\n";
	system("pause");
	return 0;
}