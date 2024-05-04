#include <iostream>
#include <algorithm>

using namespace std;

int dp[1500001];
int tlist[1500000];
int plist[1500000];

int main()
{
    int N, T, P;
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> tlist[i] >> plist[i];
    }

    int tt, tp;
    for(int i = N - 1; i > -1; i--)
    {
        if(i + tlist[i] > N)
        {
            dp[i] = dp[i + 1];
        }
        else
        {
            dp[i] = max(dp[i + 1], plist[i] + dp[i + tlist[i]]);
        }
    }

    cout << dp[0];


    return 0;
}