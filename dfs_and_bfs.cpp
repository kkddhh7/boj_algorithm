#include <iostream>
#include <vector>
#include  <queue>

using namespace std;

int N, M, V;
int e_map[1001][1001];
int d_visit[1001];
int b_visit[1001];
queue<int> b_queue;

void dfs(int v) {
	cout << v << ' ';
	d_visit[v] = 1;
	for (int i = 1; i < N + 1; i++) {
		if (e_map[v][i] == 1 && d_visit[i] != 1) {
			dfs(i);
		}
	}
}

void bfs(int v) {
	b_queue.push(v);
	b_visit[v] = 1;
	cout << v << " ";
	
	while (!b_queue.empty()) {
		v = b_queue.front();
		b_queue.pop();
		for (int i = 0; i < N + 1; i++) {
			if (e_map[v][i] == 1 && b_visit[i] != 1) {
				b_queue.push(i);
				b_visit[i] = 1;
				cout << i << " ";
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;

	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		e_map[a][b] = 1;
		e_map[b][a] = 1;
	}

	dfs(V);
	cout << endl;

	bfs(V);
	
	return 0;
}