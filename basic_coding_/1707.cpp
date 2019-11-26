//1707 �̺б׷���
//�׷����� �Է����� �־����� ��, �� �׷����� �̺� �׷�������
//�ƴ��� �Ǻ��ϴ� ���α׷��� �ۼ��Ͻÿ�.
//��������Ʈ�� �Ҳ���.
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
		//�̺б׷����� �����ҷ� �̷�����־ ��.
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