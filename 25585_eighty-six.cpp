#include <iostream>

using namespace std;

int map[11][2];

int main()
{
    int N;
    cin >> N;

    int tnum;
    int rnum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> tnum;
            if (tnum == 2)
            {
                map[0][0] = i;
                map[0][1] = j;
            }
            else if (tnum == 1)
            {
                rnum++;
                map[rnum][0] = i;
                map[rnum][1] = j;
            }
        }
    }

    int can = (map[0][0] + map[0][1]) % 2;
    for (int i = 1; i <= rnum; i++)
    {
        if (can != ((map[i][0] + map[i][1]) % 2))
        {
            cout << "Shorei";
            return 0;
        }
    }

    return 0;
}