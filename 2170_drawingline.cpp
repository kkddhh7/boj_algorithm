#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int N;
    cin >> N;
    vector< pair<int, int> > list(N);
    for(int i = 0; i < N; i++)
    {
        cin >> list[i].first >> list[i].second;
    }
    sort(list.begin(), list.end());

    int start = list[0].first;
    int end = list[0].second;
    int sum = 0;
    for(int i = 1; i < N; i++)
    {
        if(list[i].first > end)
        {
            sum += end - start;
            start = list[i].first;
            end = list[i].second;
        }
        else
        {
            end = max(end, list[i].second);
        }
    }
    sum += end - start;

    cout << sum;

    return 0;
}