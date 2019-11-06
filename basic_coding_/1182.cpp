
//#include <iostream>
//#include <vector>
//using namespace std;
//
//vector<int> v;
//int n;
//int s;
//int now = 0;
//int arr[100000] = { 0, };
//
//void go(int index,int total ) {
//	total += arr[index];
//	if (index >= n) return;
//	if (total == s) now++;
//
//	go(index + 1, total - arr[index]);
//	go(index + 1, total);
//}
//
//int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	int num;
//	cin >> n >> s;
//
//	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
//	}
//	go(0,0);
//	cout << now;
//	system("pause");
//	return 0;
//}

#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int input_n, input_s, input;
int num=0;

void go(int index, int sum) {
	if (index >= input_n) return;
		sum += v[index];
	if (sum == input_s) {
		num++;
	}
	go(index + 1, sum - v[index]);
	go(index + 1, sum);
}

int main() {
	int j;
	cin >> input_n >> input_s;
	for (int i = 0; i < input_n; i++) {
		cin >> j;
		v.push_back(j);
	}
	go(0, 0);
	cout<<num;
	system("pause");
	return 0;
}