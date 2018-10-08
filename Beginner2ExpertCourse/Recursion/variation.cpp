#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);

    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    int counter = 0;

    sort(nums.begin(), nums.end());

    for (int i = 0, j = 1; i < N; )
    {
        if (nums[j] - nums[i] >= K)
        {
            counter += N - j;
            i++;
            j = i + 1;
        }
        else
        {
            if (j < N - 1)
                j++;
            else
            {
                i++;
                j = i + 1;
            }
        }
    }

    cout << counter;
}