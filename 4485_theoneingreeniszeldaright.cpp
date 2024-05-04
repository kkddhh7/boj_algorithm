#include <iostream>
#include <vector>

using namespace std;

int map[125][125];
vector<int> ans;

int main()
{
    int N = 1;
    while (N != 0)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                if (i > 0 && j > 0)
                {
                    map[i][j] += min(map[i - 1][j], map[i][j - 1]);
                }
                else if (i == 0)
                {
                    map[i][j] += map[i][j - 1];
                }
                else if (j == 0)
                {
                    map[i][j] += map[i - 1][j];
                }
            }
        }
        
        cout << endl;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << map[i][j] << '/';
            }
            cout << endl;
        }

        ans.push_back(map[N - 1][N - 1]);
    }

    for (int i = 0; i < ans.size() - 1; i++)
    {
        cout << "Problem " << i + 1 << ": " << ans[i] << endl;
    }

    return 0;
}