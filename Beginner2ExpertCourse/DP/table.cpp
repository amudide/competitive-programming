#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> costs(N);

    for (int i = 0; i < N; i++)
    {
        cin >> costs[i];
    }

    vector<int> DP(N);
    vector<int> DP2(N);

    DP[0] = costs[0];
    DP[1] = costs[1];

    for (int i = 2; i < N; i++)
    {
        DP[i] = min(DP[i - 1], DP[i - 2]) + costs[i];
    }

    DP2[1] = costs[1];
    DP2[2] = costs[2];

    for (int i = 3; i < N - 1; i++)
    {
        DP2[i] = min(DP2[i - 1], DP2[i - 2]) + costs[i];
    }

    cout << min(DP[N - 1], costs[0] + DP2[N - 2]);
}