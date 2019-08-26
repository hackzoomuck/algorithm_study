////10927 다음 순열
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//vector<int> v;
//
//int main() {
//	int n,num;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> num;
//		v.push_back(num);
//	}
//	int i = n - 1;
//	//내림차순인지 보는 것, next_permutation은 return 값이 bool값으로 마지막순열에서 false을 return하므로 if문 사용해도 가능
//	while (i > 0 && v[i - 1] > v[i])i -= 1;
//	if (i <= 0) {
//		cout << "-1\n";
//		return 0;
//	}
//	next_permutation(v.begin(), v.end());
//	for (int i = 0; i < n; i++) {
//		cout << v[i] << " ";
//	}
//	return 0;
//}
//
////10924 모든 순열
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//vector<int> v;
//
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 1; i <= n; i++) {
//		v.push_back(i);
//	}
//	sort(v.begin(), v.end());
//	do {
//		for (int i = 0; i < n; i++) {
//			cout << v[i] << " ";
//		}
//		cout << "\n";
//	} while (next_permutation(v.begin(), v.end()));
//	system("pause");
//	return 0;
//}

////10819 차이를 최대로
////수 n개가 주어졌을 때 8이하기에 8! 가능함
//#include <iostream>
//#include <algorithm>
//#include <math.h>
//#include <vector>
//using namespace std;
//
//vector<int> v;
//int max_diff_sum=0;
//
//int main() {
//	int n,m;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> m;
//		v.push_back(m);
//	}
//	sort(v.begin(), v.end());
//	do {
//		int sum = 0;
//		for (int i = 0; i < n-1; i++) {
//			sum += abs(v[i] - v[i + 1]);
//		}
//		if (sum > max_diff_sum)max_diff_sum = sum;
//	} while (next_permutation(v.begin(), v.end()));
//	cout << max_diff_sum << "\n";
//	system("pause");
//	return 0;
//}

//10971 외판원순환2(tsp)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;
int arr[11][11] = { 0, };
int sum = 10000001;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	do {
		int ans = 0;
		for (int i = 0; i < n-1; i++) {
			if (arr[v[i]][v[i + 1]] == 0) {
				ans = 10000001;
				break;
			}
			ans += arr[v[i]][v[i + 1]];
		}
		if (sum > ans)sum = ans;
	} while (next_permutation(v.begin(), v.end()));
	cout << sum << "\n";
	system("pause");
	return 0;
}