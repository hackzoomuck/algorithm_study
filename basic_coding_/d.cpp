//Ä³½Ã
//1:45-4:36
//4:43-6:10
#include <string>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

//int solution(int cacheSize, vector<string> cities) {
//	
//	int answer = 0;
//	if (cacheSize == 0) {
//		return answer = cities.size() * 5;
//	}
//	map<string, int> m;
//	for (int i = 0; i < cities.size(); i++) {
//		for (int j = 0; j < cities[i].size(); j++) {
//			cities[i][j] = toupper(cities[i][j]);
//		}
//	}
//	int count = 0;
//	vector<pair<int, string>> v;
//	for (int i = 0; i < cities.size(); i++) {
//		if (m.find(cities[i])==m.end()) {//cache miss ¾øÀ½
//			if (m.size() == cacheSize) {//²ËÃ¡À»°æ¿ì
//				for (auto it = m.begin(); it != m.end(); it++) {
//					v.push_back(make_pair(it->second, it->first));
//				}
//				sort(v.begin(), v.end());
//				string first_key = v[0].second;
//				m.erase(first_key);
//				m.insert(make_pair(cities[i], count));
//				v.clear();
//			}
//			else {
//				m.insert(make_pair(cities[i], count));
//			}
//
//			answer += 5;
//			count++;
//		}
//		else {//cache hit
//			m.insert(make_pair(cities[i], count));
//			answer += 1;
//			count++;
//		}
//	}
//	cout << answer;
//	return answer;
//}


int solution(int cacheSize, vector<string> cities) {

	int answer = 0;
	queue<string> q;
	if (cacheSize == 0) {
		return answer = cities.size() * 5;
	}
	for (int i = 0; i < cities.size(); i++) {
		for (int j = 0; j < cities[i].size(); j++) {
			cities[i][j] = toupper(cities[i][j]);
		}
		int size = q.size();
		bool hit = false;
		for (int k = 0; k < size; k++) {
			string s_front = q.front();
			q.pop();
			if (s_front == cities[i]) {
				hit = true;
			}
			else {
				q.push(s_front);
			}
		}
		if (size == cacheSize) {
			if (hit) {
				q.push(cities[i]);
				answer += 1;
			}
			else {
				q.pop();
				q.push(cities[i]);
				answer += 5;
			}
		} 
		else {
			if (hit) {
				q.push(cities[i]);
				answer += 1;
			}
			else {
				q.push(cities[i]);
				answer += 5;
			}
		}
	}
	
	cout << answer;
	return answer;
}

int main() {
	int i_cs;
	string s_cs[4] = { "Jeju", "Jeju", "NewYork", "newyork" };
	vector<string> v_citi;
	cin >> i_cs;
	for (int i = 0; i < 4; i++) {
		v_citi.push_back(s_cs[i]);
	}
	
	solution(i_cs, v_citi);
	system("pause");
	return 0;
}