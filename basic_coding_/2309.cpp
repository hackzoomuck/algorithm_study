#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> height;

int main() {
	int hei,sum=0;
	for (int i = 0; i < 9; i++) {
		cin >> hei;
		height.push_back(hei);
		sum += hei;
	}

	bool check = false;
	int a= -1, b = -1;

	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum-(height[i] + height[j])==100) {//문제조건 제대로!
				height[i]=1000;
				height[j]=1000;
				check = true;
				break;
			}
		}
		if (check == true) break;
	}

	sort(height.begin(), height.end());
	for (int i = 0; i < 7; i++) {
		cout << height[i] << "\n";
	}
	system("pause");
	return 0;
}