#include <iostream>
#include <queue>

using namespace std;

char gear[1000][8];
int now[1000][3];
queue< pair<int, int> > q;

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            char a;
            cin >> a;
            gear[i][j] = a;
        }
        now[i][0] = 0;
        now[i][1] = 2;
        now[i][2] = 6;
    }

    int K;
    cin >> K;
    int g, d;
    for (int i = 0; i < K; i++)
    {
        cin >> g >> d;
        q.push(make_pair(g, d));

        int lg = g;
        int ln = g - 1;
        int ld = d;
        while (ln > 0)
        {
            //cout << endl << gear[lg - 1][now[lg - 1][2]] << "/////" << gear[ln - 1][now[ln - 1][1]] << endl;
            if (gear[lg - 1][now[lg - 1][2]] == gear[ln - 1][now[ln - 1][1]])
            {
                ln = 0;
            }
            else
            {
                ld *= -1;
                q.push(make_pair(ln, ld));
                lg = ln;
                ln--;
            }
        }

        int rg = g;
        int rn = g + 1;
        int rd = d;
        while (rn < T + 1)
        {
            if (gear[rg - 1][now[rg - 1][1]] == gear[rn - 1][now[rn - 1][2]])
            {
                rn = T + 1;
            }
            else
            {
                rd *= -1;
                q.push(make_pair(rn, rd));
                rg = rn;
                rn++;
            }
        }

        while(!q.empty())
        {
            int tg = q.front().first - 1;
            int td = q.front().second;

            if(td == 1)
            {
                for(int j = 0; j < 3; j++)
                {
                    now[tg][j] = (now[tg][j] + 7) % 8;
                }
            }
            else
            {
                for(int j = 0; j < 3; j++)
                {
                    now[tg][j] = (now[tg][j] + 1) % 8;
                }
            }

            q.pop();
        }

        //cout << endl;

        for(int j = 0; j < T; j++)
        {
            //cout << now[j][0] << '/' << now[j][1] << '/' << now[j][2] << endl;
        }
    }
    
    int answer = 0;
    for(int i = 0; i < T; i++)
    {
        if(gear[i][now[i][0]] == '1')
        {
            answer++;
        }
        //cout << gear[i][0] << '/' << answer << endl;
    }

    cout << answer;

    return 0;
}