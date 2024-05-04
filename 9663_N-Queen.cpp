#include <iostream>
#include <cstring>

using namespace std;

int map[15][15];

void mark(int n, int i, int N)
{
    for (int j = 0; j < N; j++)
    {
        map[n][j] = 1;
        map[j][i] = 1;
    }

    int ty = n - 1;
    int tx = i - 1;
    while (ty >= 0 && tx >= 0)
    {
        map[ty][tx] = 1;
        ty--;
        tx--;
    }

    ty = n - 1;
    tx = i + 1;
    while (ty >= 0 && tx < N)
    {
        map[ty][tx] = 1;
        ty--;
        tx++;
    }

    ty = n + 1;
    tx = i - 1;
    while (ty < N && tx >= 0)
    {
        map[ty][tx] = 1;
        ty++;
        tx--;
    }

    ty = n + 1;
    tx = i + 1;
    while (ty < N && tx < N)
    {
        map[ty][tx] = 1;
        ty++;
        tx++;
    }
}

int put_queen(int N, int n)
{
    if (n == N)
    {
        return 1;
    }

    int prev_map[15][15];
    memcpy(prev_map, map, sizeof(map));
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (map[n][i] == 0)
        {
            mark(n, i, N);
            cnt += put_queen(N, n + 1);
            memcpy(map, prev_map, sizeof(map));
        }
    }

    return cnt;
}

int main()
{
    int N;
    cin >> N;

    cout << put_queen(N, 0);

    return 0;
}