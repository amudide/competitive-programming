#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Pair;

int main()
{
    freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

    int N, B;

    cin >> N >> B;

    vector<int> tiles (N);
    vector<Pair> boots (B);

    for (int i = 0; i < N; i++)
    {
        cin >> tiles[i];
        //cout << tiles[i] << ' ';
    }
    //cout << endl;

    for (int i = 0; i < B; i++)
    {
        cin >> boots[i].first >> boots[i].second;
        //cout << boots[i].first << ' ' << boots[i].second << endl;
    }

    int currentTile = 0;
    int currentBootIndex = 0;
    int discarded = 0;
    Pair currentBoot;
    //cout << boots[0].first << ' ' << boots[0].second << endl;

    while (currentTile != N - 1)
    {
        currentBoot = boots[currentBootIndex];
        if (currentBoot.first < tiles[currentTile])
        {
            discarded++;
            currentBootIndex++;
            continue;
        }
        int j = 0;
        for (int i = currentTile + 1; (i <= currentTile + currentBoot.second) && (i < N); i++)
        {
            if (currentBoot.first >= tiles[i])
            {
                currentTile = i;
                j = 1;
                break;
            }
        }
        if (j == 0)
        {
            discarded++;
            currentBootIndex++;
        }

        //cout << currentTile << ' ' << discarded << endl;
    }

    cout << discarded;
}