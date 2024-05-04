#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

bool button[10] = { true, true, true, true, true, true, true, true, true, true };

bool is_possible(int num)
{
    string n = to_string(num);
    for(int i = 0; i < n.size(); i++)
    {
        if(!button[n[i] - '0'])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int num;
        cin >> num;
        button[num] = false;
    }

    for(int i = 0; i < 10; i++)
    {
        cout << button[i] << '/';
    }
    cout << endl;

    int ans = abs(N - 100);

	for (int i = 0; i <= 1000000; i++)
    {
		if (is_possible(i)) 
        {
			int temp = abs(N - i) + to_string(i).size();
			ans = min(ans, temp);
		}
	}

	cout << ans;

    return 0;
}