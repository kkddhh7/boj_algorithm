#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;
priority_queue<int> d;

int main()
{
    int N, K, n;
    cin >> N;
    cin >> K;
    for(int i = 0; i < N; i++)
    {
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < N - 1; i++)
    {
        d.push(v[i + 1] - v[i]);
    }

    int counter = K - 1;
    int sum = 0;
    while(!d.empty())
    {
        if(counter > 0)
        {
            counter--;
        }
        else
        {
            sum += d.top();
        }

        d.pop();
    }

    cout << sum;


    return 0;
}