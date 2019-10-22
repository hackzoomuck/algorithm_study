#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int check[101] = { 0, };//다른 담 내에 존재 0이상, 아니면 0
int arr[101][3] = { 0, };//arr[i][0] x좌표,arr[i][1] y좌표,arr[i][2] 반지름 
vector<int> v[101];

int main() {
	int number = 0;
	int  section_number;
	int x, y, radius;
	int start, end;

	cin >> number;
	for (int i = 0; i < number; i++) {
		cin >> section_number >> x >> y >> radius;
		arr[section_number][0] = x;
		arr[section_number][1] = y;
		arr[section_number][2] = radius;
	}
	for (int i = 1; i < number; i++) {
		for (int j = i + 1; j <= number; j++) {
			if (pow(arr[i][0] - arr[j][0], 2) + pow(arr[i][1] - arr[j][1], 2) < pow(arr[i][2], 2) + pow(arr[j][2], 2)) {
				if (arr[i][2] > arr[j][2]) check[j]++;
				else check[i]++;
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
	}
	for (int i = 1; i <= number; i++) {
		if (!check[i]) {
			v[0].push_back(i);
			v[i].push_back(0);
		}
	}
	check[0] = -1;
	cin >> start >> end;
	vector<int> s_v;
	vector<int> e_v;
	bool b = true;
	while (b) {
		if (start == end) break;
		if (check[start] > check[end]) {
			s_v.push_back(start);
			for (int j = 0; j < v[start].size(); j++) {
				if (check[v[start][j]] == check[start] - 1) {
					start = v[start][j];
					break;
				}
			}
			continue;
		}
		if (check[start] < check[end]) {
			e_v.push_back(end);
			for (int j = 0; j < v[end].size(); j++) {
				if (check[v[end][j]] == check[end] - 1) {
					end = v[end][j];
					break;
				}
			}
			continue;
		}
		s_v.push_back(start);
		for (int j = 0; j < v[start].size(); j++) {
			if (check[v[start][j]] == check[start] - 1) {
				start = v[start][j];
				break;
			}
		}		
		e_v.push_back(end);
		for (int j = 0; j < v[end].size(); j++) {
			if (check[v[end][j]] == check[end] - 1) {
				end = v[end][j];
				break;
			}
		}
	}

	for (int i = 0; i < s_v.size(); i++) {
		cout << s_v[i] << " ";
	}
	cout << start << " ";
	for (int i = 0; i < e_v.size(); i++) {
		cout << e_v[e_v.size() - 1 - i] << " ";
	}
	system("pause");
	return 0;
}