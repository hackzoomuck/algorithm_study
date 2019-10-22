#include <iostream>
using namespace std;

int arr[100][100][100] = { 0, };
int dm[6] = {0,0,0,0,-1,1};
int dn[6] = {0,0,-1,1,0,0};
int dh[6] = {-1,1,0,0,0,0};
int zero_count = 0;
int date = 0;

void bfs(int ih,int in,int im) {
	int nh;
	int nn;
	int nm;
	while
}
int main() {
	int m, n, h;
	cin >> m >> n >> h;
	for(int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cout << arr[i][j][k]<<" ";
			}
			cout << "\n";
		}
		cout << "--------------------\n";
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[i][j][k] == 1) {
					bfs(i, j, k);
				}
			}
		}
	}
	system("pause");
	return 0;
}