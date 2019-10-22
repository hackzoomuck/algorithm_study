#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool compare(pair<double, int> a, pair<double, int> b)
{
	// 실패율이 같다면 스테이지 번호가 작은것!
	if (a.first == b.first)
		return a.second < b.second;

	// 실패율이 큰것이 앞!
	return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
	int total_users = stages.size();
	double stage_player = 0;
	double stage_count[501] = { 0, };
	vector<pair<double,int>> stage_failrate;
	vector<int> answer;
	sort(stages.begin(), stages.end());
	for (int i = 1; i <= N; i++) {
		stage_player = 0;
		for (int j = 0; j < stages.size(); j++) {
			if (i == stages[j]) stage_count[i]++;
			if (i <= stages[j]) stage_player++;
		}
		if (stage_player == 0) {
			stage_failrate.push_back({0,i});
		}
		else {
			double d = stage_count[i] / stage_player;
			cout << stage_count[i] <<" "<< stage_player<<" "<<d<<" ";
			stage_failrate.push_back({ (stage_count[i] / stage_player),i });
		}
	}
	sort(stage_failrate.begin(), stage_failrate.end(),compare);
	answer.resize(stage_failrate.size());
	for (int i = 0; i < stage_failrate.size(); i++) {
		answer.push_back(stage_failrate[i].second);
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	return answer;
}

int main() {
	int _n,tmp,_m;
	vector<int> _stages;
	cin >> _n>>_m;
	for (int i = 0; i < _m; i++) {
		cin >> tmp;
		_stages.push_back(tmp);
	}
	solution(_n, _stages);
	system("pause");
	return 0;
}