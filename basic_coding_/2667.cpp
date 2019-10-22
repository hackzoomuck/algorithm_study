#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
char arr[26][26] = { 0, };
int check[26][26] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
int blockcount = 0;
vector<int> v;

void dfs(int x,int y, int num) {
	int nx;
	int ny;
	for (int i = 0; i < 4; i++) {
		nx = x + dx[i];
		ny = y + dy[i];
		if (0<= nx && nx < N && 0<= ny && ny < N && arr[nx][ny]=='1' && check[nx][ny]==0 ) {
			check[nx][ny] = 1;
			blockcount++;
			dfs(nx, ny, num);
		}
	}
}
int main() {
	int input;
	int number = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j]=='1'&& check[i][j]==0) {
				number++;
				check[i][j] = 1;
				blockcount++;
				dfs(i, j, number);
				v.push_back(blockcount);
				blockcount = 0;
			}
		}
	}
	cout << number<<"\n";
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
	system("pause");
	return 0;
}