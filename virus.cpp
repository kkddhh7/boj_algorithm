#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int vmap[101];

int main() {
	int num, n;
	cin >> num;
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	queue<int> qq;
	qq.push(1);
	while (!qq.empty()) {
		a = qq.front();
		for (int i = 1; i < num + 1; i++) {
			if (map[a][i] == 1) {
				if (vmap[i] != 1) {
					qq.push(i);
				}
				map[i][a] = 0;
			}
		}
		vmap[a] = 1;
		qq.pop();
	}

	int count = 0;
	for (int i = 2; i < num + 1; i++) {
		count += vmap[i];
	}

	cout << count;

	return 0;
}