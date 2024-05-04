#include <iostream>
#include <queue>

using namespace std;

int map[500][500];
queue< pair<int, int> > q;

int main() 
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }
    
    int count = 0, bs = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(map[i][j] == 1)
            {
                map[i][j] = 0;
                q.push(make_pair(i,j));
                int ts = 1;
                while(!q.empty())
                {
                    pair<int,int> a = q.front();
                    q.pop();

                    if(a.second + 1 < m && map[a.first][a.second + 1] == 1)
                    {
                        ts++;
                        q.push(make_pair(a.first, a.second + 1));
                        map[a.first][a.second + 1] = 0;
                    }

                    if(a.second - 1 > -1 && map[a.first][a.second - 1] == 1)
                    {
                        ts++;
                        q.push(make_pair(a.first, a.second - 1));
                        map[a.first][a.second - 1] = 0;
                    }

                    if(a.first + 1 < n && map[a.first + 1][a.second] == 1)
                    {
                        ts++;
                        q.push(make_pair(a.first + 1, a.second));
                        map[a.first + 1][a.second] = 0;
                    }

                    if(a.first - 1 > -1 && map[a.first - 1][a.second] == 1)
                    {
                        ts++;
                        q.push(make_pair(a.first - 1, a.second));
                        map[a.first - 1][a.second] = 0;
                    }

                }
                count++;
                if(ts > bs) { bs = ts; }
            }
        }
    }

    cout << count << '\n' << bs;


    return 0;
}