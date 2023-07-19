#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int num = 0;
int counter = 0;
int day = 0;
int map[1000][1000];
queue<pair<int, int>> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				num++;
			}
			else if (map[i][j] == 1) {
				q.push({ i, j });
			}
		}
	}

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];
				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == 0) {
					counter++;
					q.push({ nx, ny });
					map[nx][ny] = 1;
				}
			}
		}
		day++;
	}

	if (num == counter) {
		cout << day - 1;
	}
	else {
		cout << -1;
	}

	return 0;
}