#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Pair

int main()
{
    freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

    int C, N;
    cin >> C >> N;

    vector<int> chickens (C);
    vector<Pair> cows (N);

    for (int i = 0; i < C; i++)
    {
        cin >> chickens[i];
    }

    for (int i = 0; i < N; i++)
    {
        cin >> cows[i].first >> cows[i].second;
    }

    sort(cows.begin(), cows.end());

    int pairs = 0;

    for (vector<int>::iterator it = chickens.begin(); it != chickens.end(); it++)
    {
        for (vector<Pair>::iterator jt = cows.begin(); jt != cows.end(); jt++)
        {

        }
    }
}
