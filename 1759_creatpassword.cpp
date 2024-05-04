#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
vector<char> mv;
vector<char> sv;

vector<char> mc(char a, vector<char> mv, vector<char> sv)
{
    for(int i = 0; i < sv.size() - 1; i++)
    {
        for(int j = i + 1; j < sv.size(); j++)
        {
            char b = sv[i];
            char c = sv[j];
        }
    }
}

int main()
{
    cin >> L >> C;
    char a;
    for(int i = 0; i < C; i++)
    {
        cin >> a;
        if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
        {
            mv.push_back(a);
        }
        else
        {
            sv.push_back(a);
        }
    }

    sort(mv.begin(), mv.end());
    sort(sv.begin(), sv.end());

    char a;
    for(int i = 0; i < mv.size(); i++)
    {
        a = mv[0];
        mv.erase(mv.begin());

    }
    

    return 0;
}