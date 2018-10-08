#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair;

bool comp(Pair i, Pair j) 
{ 
    return (i.first < j.first);
}

int main()
{
    int N, X, Y;
    cin >> N >> X >> Y;

    vector<Pair> contests(N);
    vector<int> thereHoles(X);
    vector<int> backHoles(Y);

    for (int i = 0; i < N; i++)
    {
        cin >> contests[i].first >> contests[i].second;
    }
    for (int i = 0; i < X; i++)
    {
        cin >> thereHoles[i];
    }
    for (int i = 0; i < Y; i++)
    {
        cin >> backHoles[i];
    }

    
    sort(thereHoles.begin(), thereHoles.end());
    sort(contests.begin(), contests.end(), comp);
    sort(backHoles.begin(), backHoles.end());

    vector<int>::iterator there = thereHoles.begin();
    int back;

    long long distance = 1e8;

    for (vector<Pair>::iterator it = contests.begin(); it != contests.end(); ++it)
    {
        int m = 0;
        while (*there <= (*it).first)
        {
            there++;
            if (*there > (*it).first)
            {
                m = 1;
            }
        }
        if (m == 1)
        {
            there--;
        }

        for (vector<int>::iterator it2 = backHoles.begin(); it2 != backHoles.end(); ++it2)
        {
            if ((*it2) >= (*it).second)
            {
                back = *it2;
                break;
            }
        }

        if (back - *there < distance)
        {
            distance = back - *there;
        }
    }

    cout << distance + 1;

    return 0;
}