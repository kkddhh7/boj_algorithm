#include <iostream>
#include <string>

using namespace std;

char S[999];
char T[1000];

int main()
{
    string s, t;
    cin >> s >> t;

    copy(s.begin(), s.end(), S);
    copy(t.begin(), t.end(), T);

    int ssize = s.size() - 1;
    int tsize = t.size() - 1;

    for (int i = 0; i < tsize - ssize; i++)
    {
        if (T[tsize - i] == 'B')
        {
            for (int j = 0; j < (tsize - i) / 2; j++)
            {
                char temp = T[j];
                T[j] = T[tsize - i - 1 - j];
                T[tsize - i - 1 - j] = temp;
            }
        }

        for (int i = 0; i <= tsize; i++)
        {
            cout << T[i];
        }
        cout << endl;
    }

    int answer = 1;
    for (int i = 0; i <= ssize; i++)
    {
        if (S[i] != T[i])
        {
            answer = 0;
            break;
        }
    }

    cout << answer;

    return 0;
}