#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, k;
    cin >> N >> k;

    vector<int> squares(N);

    for (int i = 0; i < N; i++)
    {
        cin >> squares[i];
    }

    vector<int> forwardDP(N);
    vector<int> backwardDP(N);

    forwardDP[k] = 0;
    forwardDP[k + 1] = squares[k + 1];
    
    for (int i = k + 2; i < N; i++)
    {
        forwardDP[i] = squares[i] + max(forwardDP[i - 1], forwardDP[i - 2]);
    }

    backwardDP[0] = 0;
    backwardDP[1] = squares[1];

    for (int i = 2; i < N; i++)
    {
        backwardDP[i] = squares[i] + max(backwardDP[i - 1], backwardDP[i - 2]);
    }

    for (int i = 0; i < N; i++)
    {
        backwardDP[i] = backwardDP[i] + squares[0] - squares[i];
    }

    int max = -10000;

    for (int i = k; i < N; i++)
    {
        if (backwardDP[i] + forwardDP[i] > max)
            max = backwardDP[i] + forwardDP[i];
    }

    cout << max;
}