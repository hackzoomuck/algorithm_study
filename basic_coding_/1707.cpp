//1707 이분그래프
//그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지
//아닌지 판별하는 프로그램을 작성하시오.
//인접리스트로 할꺼임.
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

//0-none, 1-a, 2-b
int group[20002] = { 0, }, v, e ;
bool yesno = true;
vector<int> adj_list[20002];

void dfs(int start,int color) {
	group[start] = color;
	for (int i = 0; i < adj_list[start].size(); i++) {
		int x = adj_list[start][i];
		if (group[x] == 0) {
			dfs(x, 3 - group[start]);
		}
		else {
			if (group[x] == group[start]) {
				yesno = false;
				return;
			}
		}
	}
}

void input() {
	int  a, b;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b;
		adj_list[a].push_back(b);
		adj_list[b].push_back(a);
	}
}

int main() {
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		input();
		//이분그래프는 연결요소로 이루어져있어도 됨.
		for (int k = 1; k <= v; k++) {
			if (group[k] == 0) {
				dfs(k, 1);
			}
		}
		if (yesno) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		for (int j = 1; j <= v; j++) {
			adj_list[j].clear();
		}
		memset(group, 0, sizeof(group));
		yesno = true;
	}

	return 0;
}