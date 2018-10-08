#include <iostream>
#include <vector>

using namespace std;


int tiling(int N, vector<long long>& answers)
{
    if (answers[N] == 0)
    {
        long long result;

        if (N == 1)
            result = 1;
        else if (N == 2)
            result = 2;
        else
            result = tiling(N - 1, answers) + tiling(N - 2, answers);

        answers[N] = result;
    }

    return answers[N];
}

int main()
{
    int N;

    cout << "Enter N: ";
    cin >> N;

    vector<long long> answers(N + 1, 0);
    
    cout << tiling(N, answers) << '\n';
}