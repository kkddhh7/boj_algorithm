#include <iostream>
#include <queue>
#include <vector>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    int N;
    cin >> N;
    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        pq.push(num);
    }

    int total = 0;
    int sum;
    int fn, sn;
    while(pq.size() != 1)
    {
        fn = pq.top();
        pq.pop();
        sn = pq.top();
        pq.pop();

        sum = fn + sn;
        total += sum;
        pq.push(sum);
    }

    cout << total;

    return 0;
}