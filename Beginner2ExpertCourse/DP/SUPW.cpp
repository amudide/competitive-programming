#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> times(N);

    for (int i = 0; i < N; i++)
    {
        cin >> times[i];
    }

    vector<int> DP(N);

    DP[0] = times[0];
    DP[1] = times[1];
    DP[2] = times[2];

    for (int i = 3; i < N; i++)
    {
        DP[i] = min(min(DP[i - 1], DP[i - 2]), DP[i - 3]) + times[i];
    }

    cout << min(min(DP[N - 1], DP[N - 2]), DP[N - 3]);
}