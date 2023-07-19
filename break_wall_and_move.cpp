#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
queue<tuple<int, int, bool>> q;
bool fvisited[1000][1000];
bool tvisited[1000][1000];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> N >> M;
	vector<string> map(N);
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	q.push({ 0,0,false });
	fvisited[0][0] = true;
	int distance = 1;

	while (!q.empty()) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = get<0>(q.front());
			int y = get<1>(q.front());
			bool z = get<2>(q.front());
			if (x == N - 1 && y == M - 1) {
				cout << distance;
				return 0;
			}
			q.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (z == false && fvisited[nx][ny] != true) {
						if (map[nx][ny] == '0') {
							q.push({ nx,ny, false });
							fvisited[nx][ny] = true;
						}
						else if (map[nx][ny] == '1') {
							q.push({ nx, ny, true });
							tvisited[nx][ny] = true;
						}
					}
					else if (z == true && map[nx][ny] == '0' && fvisited[nx][ny] != true && tvisited[nx][ny] != true) {
						q.push({ nx,ny, true });
						tvisited[nx][ny] = true;
					}
				}
			}
		}
		distance++;
	}

	cout << -1;

	return 0;
}
