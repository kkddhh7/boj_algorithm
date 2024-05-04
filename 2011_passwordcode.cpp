#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int list[5000];
int dp[5001];

int main()
{
    string num;
    cin >> num;
    int length = num.length();

    for (int i = 0; i < length; i++)
    {
        list[i] = num[i] - '0';
    }

    for (long i = 0; i < length; i++)
    {
        cout << list[i] << '/';
    }
    cout << endl;

    dp[0] = 1;
    dp[1] = 1;
    int t;
    if (list[0] == 0)
    {
        cout << 0;
    }
    else
    {
        for (int i = 1; i < length; i++)
        {
            t = 0;
            if (list[i] == 0)
            {
                if (list[i - 1] == 1 || list[i - 1] == 2)
                {
                    dp[i] = dp[i - 1];
                    dp[i + 1] = dp[i - 1];
                    dp[i + 2] = dp[i - 1];
                    i += 1;
                }
                else
                {
                    i = length + 1;
                }
            }
            else
            {
                if (list[i - 1] * 10 + list[i] < 27)
                {
                    t = dp[i - 1];
                }

                t += dp[i];
                if (t >= 1000000)
                {
                    t = t % 1000000;
                }
                dp[i + 1] = t;
            }
        }

        for (long i = 0; i < length + 1; i++)
        {
            cout << dp[i] << '/';
        }
        cout << endl;

        cout << dp[length];
    }

    return 0;
}