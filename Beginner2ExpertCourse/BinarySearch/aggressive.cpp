#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t, N, C;

int binarySearch (vector<int>& stalls, int min, int max, int size)
{
    if (min == max)
    {
        cout << "YO";
        return min;
    }
    else if (max - min == 1)
    {
        cout << "max: " << max << '\n' << "min: " << min << '\n';
        int test = max;

        int cowNumber = 0, stallNumber = 0, runningDistance = 0;

        bool worked = true;

        while (cowNumber < C)
        {
            stallNumber++;
            runningDistance += stalls[stallNumber] - stalls[stallNumber - 1]; 
            if (stallNumber == size)
            {
                worked = false;
                break;
            }
            if (runningDistance >= test)
            {
                cowNumber++;
                runningDistance = 0;
            }  
        }

        if (worked)
        {
            return max;
        }
        else
        {
            return min;
        }
    }
    int test = (min + max) / 2;

    int cowNumber = 0, stallNumber = 0, runningDistance = 0;

    bool worked = true;

    while (cowNumber < C)
    {
        stallNumber++;
        runningDistance += stalls[stallNumber] - stalls[stallNumber - 1]; 
        if (stallNumber == size)
        {
            worked = false;
            break;
        }
        if (runningDistance >= test)
        {
            cowNumber++;
            runningDistance = 0;
        }
    }

    if (worked)
    {
        return binarySearch(stalls, test, max, size);
    }
    else
    {
        return binarySearch(stalls, min, test - 1, size);
    }

}

int main ()
{
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> N >> C;
        vector<int> stalls(N);

        for (int j = 0; j < N; j++)
        {
            cin >> stalls[j];
        }
        sort(stalls.begin(), stalls.end());
        cout << binarySearch(stalls, 0, stalls[N - 1] - stalls[0], N) << endl;
    }
}