#include <iostream>
#include <queue>

using namespace std;

char map[100][100];
char rgmap[100][100];
queue < pair<int,int> > q;


int main()
{
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            char a;
            cin >> a;
            map[i][j] = a;
            if(a == 'G')
            {
                rgmap[i][j] = 'R';
            }
            else
            {
                rgmap[i][j] = a;
            }
        }
    }

    int count = 0;
    int rgcount = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(map[i][j] != ' ')
            {
                q.push(make_pair(i,j));
                char temp = map[i][j];
                map[i][j] = ' ';
                count++;
                while(!q.empty())
                {
                    pair<int, int> a = q.front();
                    q.pop();
                    if(a.first + 1 < N && temp == map[a.first + 1][a.second])
                    {
                        map[a.first + 1][a.second] = ' ';
                        q.push(make_pair(a.first + 1, a.second));
                    }

                    if(a.first - 1 > -1 && temp == map[a.first - 1][a.second])
                    {
                        map[a.first - 1][a.second] = ' ';
                        q.push(make_pair(a.first - 1, a.second));
                    }

                    if(a.second + 1 < N && temp == map[a.first][a.second + 1])
                    {
                        map[a.first][a.second + 1] = ' ';
                        q.push(make_pair(a.first, a.second + 1));
                    }

                    if(a.second - 1 > -1 && temp == map[a.first][a.second - 1])
                    {
                        map[a.first][a.second - 1] = ' ';
                        q.push(make_pair(a.first, a.second - 1));
                    }
                }
            }

            if(rgmap[i][j] != ' ')
            {
                q.push(make_pair(i,j));
                char temp = rgmap[i][j];
                rgmap[i][j] = ' ';
                rgcount++;
                while(!q.empty())
                {
                    pair<int, int> a = q.front();
                    q.pop();
                    
                    if(a.first + 1 < N && temp == rgmap[a.first + 1][a.second])
                    {
                        rgmap[a.first + 1][a.second] = ' ';
                        q.push(make_pair(a.first + 1, a.second));
                    }

                    if(a.first - 1 > -1 && temp == rgmap[a.first - 1][a.second])
                    {
                        rgmap[a.first - 1][a.second] = ' ';
                        q.push(make_pair(a.first - 1, a.second));
                    }

                    if(a.second + 1 < N && temp == rgmap[a.first][a.second + 1])
                    {
                        rgmap[a.first][a.second + 1] = ' ';
                        q.push(make_pair(a.first, a.second + 1));
                    }

                    if(a.second - 1 > -1 && temp == rgmap[a.first][a.second - 1])
                    {
                        rgmap[a.first][a.second - 1] = ' ';
                        q.push(make_pair(a.first, a.second - 1));
                    }
                }
                
            }
        }
    }


    cout << count << ' ' << rgcount;

    return 0;
}