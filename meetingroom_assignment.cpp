#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

vector <pair<int, int>> v;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int num;
	cin >> num;

	int a, b;
	for (int i = 0; i < num; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	sort(v.begin(), v.end(), compare);


	int count = 1;
	pair<int, int> tp = v[0];
	for (int i = 1; i < num; i++) {
		if (tp.second <= v[i].first) {
			tp = v[i];
			count++;
		}
	}

	cout << count;

	return 0;
}