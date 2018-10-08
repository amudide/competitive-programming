#include <iostream>

using namespace std;

int sqrt(int N, int min, int max)
{
    int test = (min + max) / 2;
    int testSquare = test * test;

    if (max < min)
    {
        return -1;
    }
    if (N == testSquare)
    {
        return test;
    }
    else if (N > testSquare)
    {
        sqrt(N, test + 1, max);
    }
    else
    {
        sqrt(N, min, test - 1);
    }
}

int main()
{
    int N;
    cout << "Enter Perfect Square N Such That 1 <= N <= 1,000,000: ";
    cin >> N;

    cout << sqrt(N, 1, 1000) << '\n';
}   