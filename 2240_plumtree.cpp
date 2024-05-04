#include <iostream>

using namespace std;

int list[1000];
int wlist[31];

int main()
{
    int T, W;
    cin >> T >> W;

    int temp;
    for(int i = 0; i < T; i++)
    {
        cin >> temp;
        if(temp == 1)
        {
            wlist[0] += 1;
            for(int j = 1; 2 * j <= W; j++)
            {
                wlist[2 * j] = max(wlist[2 * j], wlist[2 * j - 1]) + 1;
            }
        }
        else
        {
            for(int j = 1; 2 * j - 1<= W; j++)
            {
                wlist[2 * j - 1] = max(wlist[2 * j - 1], wlist[2 * j - 2]) + 1;
            }
        }
    }

    int answer = 0;
    for(int i = 0; i <= W; i++)
    {
        if(wlist[i] > answer)
        {
            answer = wlist[i];
        }
    }

    cout << answer;

    return 0;
}