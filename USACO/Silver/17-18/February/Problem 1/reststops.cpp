#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Pair;

int main()
{
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);

    long long L, N, rF, rB;
    
    cin >> L >> N >> rF >> rB;

    vector<Pair> potential (N);
    vector<Pair> real;


    for (int i = 0; i < N; i++)
    {
        cin >> potential[i].first >> potential[i].second;
    }

    vector<Pair>::iterator it = potential.begin();
    vector<Pair>::iterator max = potential.begin();
    vector<Pair>::iterator temp = potential.end();
    temp--;

    while (1)
    {
        long long currentMax = -1;
        long long distance;
        for ( ; it != potential.end(); it++)
        {
            if ((*it).second > currentMax)
            {
                currentMax = (*it).second;
                distance = (*it).first;
                max = it;
            }
        }
        it = max;
        if (it == temp)
        {
            real.push_back(make_pair(distance, currentMax));
            break;
        }
        it++;
        real.push_back(make_pair(distance, currentMax));
    }
    

    long long units = 0;

    vector<Pair>::iterator it2 = real.begin();
    units += (*it2).second * (rF - rB) * (*it2).first;
    it2++;
    vector<Pair>::iterator it3 = real.begin();

    for ( ; it2 != real.end(); it2++, it3++)
    {
        units += (*it2).second * (rF - rB) * ((*it2).first - (*it3).first);
    }
    
    cout << (long long) units;

	return 0;
}