#include <string>
#include <set>
#include <vector>

using namespace std;

int solution(vector<vector<string>> relation) {
	int answer = 0;
	set<int> index;
	set<string> s;
	for (int i = 0; i < relation[i].size(); i++) {
		int count = 0;
		for (int j = 0; j < relation.size(); j++){
			if (s.find(relation[j][i]) == s.end()) {
				s.insert(relation[j][i]);
				count++;
			}
		}
		if (count == relation[i].size()) {

		}
	}
	return answer;
}

int main() {
	vector<vector<string>> input;

	return 0;
}