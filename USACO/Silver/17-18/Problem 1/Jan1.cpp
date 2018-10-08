#include <bits/stdc++.h>

using namespace std;

int minAloneTime = 1000000001;
map <int, int> lifeguards;
int initialTime = 0;

void getMinAlone (map <int, int> :: iterator itr1, map <int, int> :: iterator itr2)
{
	int aloneCounter;
	for (itr1 = lifeguards.begin(); itr1 != lifeguards.end(); ++itr1)
    {
    	aloneCounter = itr1 -> second - itr1 -> first;
    	for (int i = itr1 -> first; i < itr1 -> second; i++)
    	{
    		for (itr2 = lifeguards.begin(); itr2 != lifeguards.end(); ++itr2)
    		{
    			if (itr1 == itr2)
    				continue;
    			if (i >= itr2 -> first && i < itr2 -> second)
    			{
    				aloneCounter--;
    				break;
    			}
    		}
    	}
    	if (aloneCounter < minAloneTime)
    		minAloneTime = aloneCounter;
    	if (minAloneTime == 0)
    		return;
    }
}

void getInitialTime(map <int, int> :: iterator itr, map <int, int> :: iterator itr3)
{
	itr = lifeguards.begin();
	initialTime += itr -> second - itr -> first;
	itr++;
	itr3 = lifeguards.begin();

	for ( ; itr != lifeguards.end(); ++itr, ++itr3)
    {
        if (itr -> first < itr3 -> second)
        {
        	if (!(itr -> second < itr3 -> second))
        		initialTime += itr -> second - itr3 -> second;
        }
        else 
        	initialTime += itr -> second - itr -> first;
    }
}

int main()
{
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	int N;
	cin >> N;

	int x, y;

	for (int i = 0; i < N; i++)
	{
		cin >> x >> y;
		lifeguards.insert(pair <int, int> (x, y));
	}

	map <int, int> :: iterator itr1, itr2;
/*
	for (itr = lifeguards.begin(); itr != lifeguards.end(); ++itr)
    {
        cout << itr->first << '\t' << itr->second << '\n';
    }
    cout << endl;
*/
    getMinAlone(itr1, itr2);
    getInitialTime(itr1, itr2);


    cout << initialTime - minAloneTime;

	return 0;
}