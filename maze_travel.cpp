#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int N, M;
bool visited[100][100];
queue<pair<int, int>> q;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	q.push({ 0,0 });
	visited[0][0] = true;
	int distance = 1;

	while (!q.empty()) {
		int qsize = q.size();

		for (int i = 0; i < qsize; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M && map[nx][ny] == '1' && visited[nx][ny] == false) {
					if (nx == N - 1 && ny == M - 1) {
						cout << distance + 1;
						return 0;
					}
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
		distance++;
	}

	return 0;
}