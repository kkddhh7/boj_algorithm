#include <iostream>
#include <algorithm>

using namespace std;

int crainlist[50];
int clocation[50];
int boxlist[10000];

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> crainlist[i];
    }
    sort(crainlist, crainlist + N);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> boxlist[i];
    }
    sort(boxlist, boxlist + M);

    if (crainlist[N - 1] < boxlist[M - 1])
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < N; i++)
    {
        clocation[i] = M - 1;
    }

    int ans = 0;
    int sum = 0;
    while (true)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = clocation[i]; j >= -1; j--)
            {
                if (boxlist[j] != 0 && boxlist[j] <= crainlist[i])
                {
                    clocation[i] = j - 1;
                    boxlist[j] = 0;
                    j = -2;
                }

                if (j == -1)
                {
                    clocation[i] = -2;
                    sum++;
                }
            }
        }

        ans++;

        if (sum == N)
        {
            break;
        }
    }

    cout << ans - 1;

    return 0;
}