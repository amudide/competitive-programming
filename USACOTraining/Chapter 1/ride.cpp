/*
ID: anishm
TASK: ride
LANG: C++11                 
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	freopen("ride.in", "r", stdin);
	freopen("ride.out", "w", stdout);

    string comet, group;

    cin >> comet >> group;

    int clen = comet.length(), glen = group.length(), cmod = 1, gmod = 1;

    for (int i = 0; i < clen; i++)
    {
        cmod *= (comet[clen] - 64);
    }

    cmod %= 47;

    for (int j = 0; j < glen; j++)
    {
        gmod *= (group[glen] - 64);
    }

    gmod %= 47;

    if (gmod == cmod)
        cout << "GO" << endl;
    else
        cout << "STAY" << endl;

	return 0;
}