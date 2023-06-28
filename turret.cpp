#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	int num;
	int x1, y1, x2, y2, r1, r2;
	vector<int> list;

	cin >> num;
	for (int i = 0; i < num; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		double t_distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		int sum_distance = r1 + r2;

		if (t_distance > sum_distance) {
			list.push_back(0);
		}
		else if (t_distance == sum_distance) {
			list.push_back(1);
		}
		else if (t_distance < sum_distance) {
			if (r1 == r2 + t_distance || r2 == r1 + t_distance) {
				if (t_distance == 0) {
					list.push_back(-1);
				}
				else {
					list.push_back(1);
				}
			}
			else if (r1 > r2 + t_distance || r2 > r1 + t_distance) {
				list.push_back(0);
			}
			else {
				list.push_back(2);
			}
		}
	}
	
	for (auto a : list) {
		cout << a << endl;
	}

	return 0;
}