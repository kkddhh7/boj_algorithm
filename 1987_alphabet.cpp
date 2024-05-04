#include <iostream>
#include <algorithm>
using namespace std;

int R, C, result;
char board[20][20];
bool visited[26];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void DFS(int x, int y, int cnt)
{
    result = max(result, cnt);
    visited[board[x][y] - 'A'] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < R && ny < C)
        {
            if (!visited[board[nx][ny] - 'A'])
            {
                DFS(nx, ny, cnt + 1);
                visited[board[nx][ny] - 'A'] = false;
            }
        }
    }
}

int main()
{
    cin >> R >> C;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }

    DFS(0, 0, 1);
    cout << result;

    return 0;
}
