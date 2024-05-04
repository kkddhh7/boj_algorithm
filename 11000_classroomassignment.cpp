#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector< pair<int, int> > v;
priority_queue< int, vector<int>, greater<int> > pq;

int main()
{
    int N;
    cin >> N;

    int s, e;
    for (int i = 0; i < N; i++)
    {
        cin >> s >> e;
        v.push_back(make_pair(s, e));
    }
    sort(v.begin(), v.end());

    int counter = 0;
    for(int i = 0; i < N; i++)
    {
        if(!pq.empty() && pq.top() <= v[i].first)
        {
            pq.pop();    
        }
        else
        {
            counter++;
        }
        
        pq.push(v[i].second);
    }

    cout << counter;

    return 0;
}