#include <iostream>
#include <vector>

using namespace std;


int tiling (int N)
{
    if (N == 1)
        return 1;
    if (N == 2)
        return 2;
    
    return tiling(N - 1) + tiling(N - 2);
}

int main()
{
    int N;

    cout << "Enter n: ";
    cin >> N;

    cout << tiling(N) << '\n';
}