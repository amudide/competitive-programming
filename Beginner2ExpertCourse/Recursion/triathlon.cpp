#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool comp (tuple<int, int, int> i, tuple<int, int, int> j)
{
    return ((get<1>(i) + get<2>(i)) >= (get<1>(j) + get<2>(j)));
}

int main ()
{
    int N;
    cin >> N;

    vector<tuple<int, int, int>> citizens(N);

    for (int i = 0; i < N; i++)
    {
        cin >> get<0>(citizens[i]) >> get<1>(citizens[i]) >> get<2>(citizens[i]);
    }

    sort(citizens.begin(), citizens.end(), comp);

    long long maxTime = 0;
    long long runningCodingTime = 0;
    long long currentTime;

    for (int i = 0; i < N; i++)
    {
        runningCodingTime += get<0>(citizens[i]);

        currentTime = runningCodingTime + get<1>(citizens[i]) + get<2>(citizens[i]);

        if (currentTime > maxTime)
        {
            maxTime = currentTime;
        }
    }

    cout << maxTime;
}